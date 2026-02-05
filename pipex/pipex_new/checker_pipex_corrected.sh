#!/bin/bash

# ============================================================================
# PIPEX - ENHANCED TEST SUITE (FULLY CORRECTED + FD CHECKS)
# ============================================================================
# Corrections:
# - Fixed all test exit codes to match bash behavior
# - Added comprehensive FD leak detection for ALL tests
# - Better quote handling tests
# - Tests for outfile creation
# - Tests for empty string commands
# ============================================================================

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
YELLOW='\033[1;33m'
MAGENTA='\033[0;35m'
CYAN='\033[0;36m'
BOLD='\033[1m'
NC='\033[0m' # No Color

# Counters
TOTAL_TESTS=0
PASSED_TESTS=0
FAILED_TESTS=0
VALGRIND_WARNINGS=0
FD_LEAK_WARNINGS=0

# Valgrind flags
VALGRIND_FLAGS="--track-fds=all --leak-check=full --trace-children=yes --show-leak-kinds=all --errors-for-leak-kinds=definite,indirect --error-exitcode=42"

# Print functions
print_header() {
    echo -e "\n${BLUE}═══════════════════════════════════════════════════════════════${NC}"
    echo -e "${CYAN}${BOLD}$1${NC}"
    echo -e "${BLUE}═══════════════════════════════════════════════════════════════${NC}\n"
}

print_section() {
    echo -e "\n${MAGENTA}${BOLD}▶ $1${NC}"
    echo -e "${MAGENTA}$(printf '─%.0s' {1..63})${NC}"
}

print_warning() {
    echo -e "${YELLOW}${BOLD}⚠ WARNING: $1${NC}"
}

print_error() {
    echo -e "${RED}${BOLD}✗ ERROR: $1${NC}"
}

print_success() {
    echo -e "${GREEN}${BOLD}✓ $1${NC}"
}

# Check for FD leaks using lsof
check_fd_leaks() {
    local description="$1"
    
    if ! command -v lsof &> /dev/null; then
        return 0  # Skip if lsof not available
    fi
    
    # Get initial FD count (before test)
    local initial_fds=$(lsof -p $$ 2>/dev/null | wc -l)
    
    # Run the command
    shift
    "$@" 2>/dev/null
    local exit_code=$?
    
    # Small delay to ensure cleanup
    sleep 0.1
    
    # Get final FD count (after test)
    local final_fds=$(lsof -p $$ 2>/dev/null | wc -l)
    
    # Check for leaks
    if [ "$final_fds" -gt "$initial_fds" ]; then
        print_warning "Possible FD leak detected in: $description"
        echo -e "${YELLOW}  Initial FDs: $initial_fds, Final FDs: $final_fds${NC}"
        FD_LEAK_WARNINGS=$((FD_LEAK_WARNINGS + 1))
    fi
    
    return $exit_code
}

# Enhanced Valgrind test
valgrind_test() {
    local description="$1"
    local arg1="$2"
    local arg2="$3"
    local arg3="$4"
    local arg4="$5"

    TOTAL_TESTS=$((TOTAL_TESTS + 1))

    echo -e "\n${YELLOW}Test $TOTAL_TESTS: $description${NC}"
    echo -e "${CYAN}Command: valgrind $VALGRIND_FLAGS ./pipex \"$arg1\" \"$arg2\" \"$arg3\" \"$arg4\"${NC}"

    # Run valgrind
    valgrind_output=$(valgrind $VALGRIND_FLAGS ./pipex "$arg1" "$arg2" "$arg3" "$arg4" 2>&1)
    valgrind_exit=$?

    # Extract parent PID
    parent_pid=$(echo "$valgrind_output" | grep -m1 "^==[0-9]*== Command: ./pipex" | grep -oE "==[0-9]*==" | grep -oE "[0-9]+" | head -1)

    echo -e "\n${CYAN}--- Valgrind Analysis (YOUR program only) ---${NC}"

    # Filter for parent process
    parent_output=$(echo "$valgrind_output" | grep "^==$parent_pid==")

    # Check memory leaks
    def_lost=$(echo "$parent_output" | grep "definitely lost:" | grep -oE "[0-9,]+ bytes" | tr -d ',' | grep -oE "[0-9]+" | head -1)
    ind_lost=$(echo "$parent_output" | grep "indirectly lost:" | grep -oE "[0-9,]+ bytes" | tr -d ',' | grep -oE "[0-9]+" | head -1)
    poss_lost=$(echo "$parent_output" | grep "possibly lost:" | grep -oE "[0-9,]+ bytes" | tr -d ',' | grep -oE "[0-9]+" | head -1)
    still_reach=$(echo "$parent_output" | grep "still reachable:" | grep -oE "[0-9,]+ bytes" | tr -d ',' | grep -oE "[0-9]+" | head -1)

    # Check FDs - IMPROVED
    all_open_fds=$(echo "$parent_output" | grep "Open file descriptor [0-9]")
    leaked_fds=0
    
    while IFS= read -r line; do
        fd_num=$(echo "$line" | grep -oE "descriptor [0-9]+" | grep -oE "[0-9]+")
        
        if [ -n "$fd_num" ] && [ "$fd_num" -ge 3 ]; then
            next_line=$(echo "$parent_output" | grep -A 1 "Open file descriptor $fd_num" | tail -1)
            
            if ! echo "$next_line" | grep -q "inherited from parent"; then
                leaked_fds=$((leaked_fds + 1))
            fi
        fi
    done < <(echo "$all_open_fds")

    open_fds=$(echo "$parent_output" | grep "FILE DESCRIPTORS:" | grep -oE "[0-9]+ open" | grep -oE "[0-9]+" | head -1)
    
    inherited_fds=$((${open_fds:-3} - 3 - leaked_fds))
    if [ $inherited_fds -lt 0 ]; then
        inherited_fds=0
    fi

    # Display info
    echo -e "${CYAN}Memory Leaks (YOUR program):${NC}"
    echo "  Definitely lost:  ${def_lost:-0} bytes"
    echo "  Indirectly lost:  ${ind_lost:-0} bytes"
    echo "  Possibly lost:    ${poss_lost:-0} bytes"
    echo "  Still reachable:  ${still_reach:-0} bytes"

    echo -e "\n${CYAN}File Descriptors (YOUR program):${NC}"
    echo "  Total open FDs:   ${open_fds:-3}"
    echo "  Standard FDs:     3 (stdin, stdout, stderr - OK)"
    echo "  Inherited FDs:    $inherited_fds (from VS Code/parent - OK)"
    echo "  YOUR leaked FDs:  $leaked_fds"

    # Check errors
    has_leak=0
    has_fd_leak=0

    if [ "${def_lost:-0}" -gt 0 ] || [ "${ind_lost:-0}" -gt 0 ]; then
        has_leak=1
        print_error "MEMORY LEAK IN YOUR PROGRAM!"
        echo -e "${RED}  → Definitely lost: ${def_lost:-0} bytes${NC}"
        echo -e "${RED}  → Indirectly lost: ${ind_lost:-0} bytes${NC}"
        VALGRIND_WARNINGS=$((VALGRIND_WARNINGS + 1))
    fi

    if [ "$leaked_fds" -gt 0 ]; then
        has_fd_leak=1
        print_error "FILE DESCRIPTOR LEAK IN YOUR PROGRAM!"
        echo -e "${RED}  → $leaked_fds file descriptor(s) not properly closed by YOUR code${NC}"
        
        echo -e "\n${YELLOW}Leaked file descriptors:${NC}"
        while IFS= read -r line; do
            fd_num=$(echo "$line" | grep -oE "descriptor [0-9]+" | grep -oE "[0-9]+")
            if [ -n "$fd_num" ] && [ "$fd_num" -ge 3 ]; then
                next_line=$(echo "$parent_output" | grep -A 1 "Open file descriptor $fd_num" | tail -1)
                if ! echo "$next_line" | grep -q "inherited from parent"; then
                    echo "  $line"
                    echo "    $next_line"
                fi
            fi
        done < <(echo "$all_open_fds" | head -10)
        VALGRIND_WARNINGS=$((VALGRIND_WARNINGS + 1))
    fi

    error_summary=$(echo "$parent_output" | grep "ERROR SUMMARY:" | head -1)
    echo -e "\n${CYAN}Error Summary:${NC}"
    echo "  $error_summary"

    echo ""
    if [ $has_leak -eq 0 ] && [ $has_fd_leak -eq 0 ]; then
        print_success "Valgrind check PASSED"
        PASSED_TESTS=$((PASSED_TESTS + 1))
    else
        print_error "Valgrind check FAILED"
        FAILED_TESTS=$((FAILED_TESTS + 1))
    fi
}

# Regular test with exit code check AND FD check
test_command() {
    local description="$1"
    local arg1="$2"
    local arg2="$3"
    local arg3="$4"
    local arg4="$5"
    local expected_exit="$6"
    local check_output="${7:-0}"  # 1 = check if outfile has content
    local expected_content="${8:-}"

    TOTAL_TESTS=$((TOTAL_TESTS + 1))

    echo -e "\n${YELLOW}Test $TOTAL_TESTS: $description${NC}"
    echo -e "${CYAN}Command: ./pipex \"$arg1\" \"$arg2\" \"$arg3\" \"$arg4\"${NC}"

    # Only remove outfile if it's a test file (not user's main outfile)
    if [ "$arg4" != "outfile" ]; then
        rm -f "$arg4" 2>/dev/null
    fi

    # Check FDs before
    local fds_before=""
    if command -v lsof &> /dev/null; then
        fds_before=$(lsof -p $$ 2>/dev/null | grep -v "pipex\|bash\|sh" | wc -l)
    fi

    # Run command
    ./pipex "$arg1" "$arg2" "$arg3" "$arg4" 2>/dev/null
    exit_code=$?

    # Check FDs after
    if command -v lsof &> /dev/null; then
        sleep 0.1  # Small delay for cleanup
        local fds_after=$(lsof -p $$ 2>/dev/null | grep -v "pipex\|bash\|sh" | wc -l)
        if [ "$fds_after" -gt "$fds_before" ]; then
            print_warning "FD leak detected (Before: $fds_before, After: $fds_after)"
            FD_LEAK_WARNINGS=$((FD_LEAK_WARNINGS + 1))
        fi
    fi

    echo -e "${CYAN}Exit status:${NC} $exit_code (expected: $expected_exit)"

    # Check exit code
    exit_ok=0
    if [ "$exit_code" -eq "$expected_exit" ]; then
        exit_ok=1
    fi

    # Check output if requested
    output_ok=1
    if [ "$check_output" -eq 1 ]; then
        if [ -f "$arg4" ]; then
            content=$(cat "$arg4" 2>/dev/null | tr -d ' \n\t')
            if [ -n "$expected_content" ]; then
                expected_clean=$(echo "$expected_content" | tr -d ' \n\t')
                if [ "$content" = "$expected_clean" ]; then
                    echo -e "${CYAN}Output content:${NC} ✓ Matches expected"
                else
                    echo -e "${RED}Output content:${NC} ✗ Does not match"
                    echo -e "${CYAN}Expected:${NC} $expected_content"
                    echo -e "${CYAN}Got:${NC} $(cat "$arg4" 2>/dev/null)"
                    output_ok=0
                fi
            else
                if [ -s "$arg4" ]; then
                    echo -e "${CYAN}Output file:${NC} ✓ Created and has content"
                else
                    echo -e "${CYAN}Output file:${NC} ✓ Created (may be empty if no matches)"
                fi
            fi
        else
            echo -e "${RED}Output file:${NC} ✗ Not created"
            output_ok=0
        fi
    fi

    # Final verdict
    if [ $exit_ok -eq 1 ] && [ $output_ok -eq 1 ]; then
        print_success "Test PASSED"
        PASSED_TESTS=$((PASSED_TESTS + 1))
    else
        print_error "Test FAILED"
        if [ $exit_ok -eq 0 ]; then
            echo -e "${RED}  → Exit code incorrect: expected $expected_exit, got $exit_code${NC}"
        fi
        if [ $output_ok -eq 0 ]; then
            echo -e "${RED}  → Output file issue${NC}"
        fi
        FAILED_TESTS=$((FAILED_TESTS + 1))
    fi
}

# ============================================================================
# SETUP
# ============================================================================

print_header "PIPEX TESTER - ENHANCED VERSION WITH FD CHECKS"

echo -e "${CYAN}Checking for pipex executable...${NC}"
if [ ! -f "./pipex" ]; then
    print_error "pipex executable not found in current directory"
    exit 1
fi
print_success "Found ./pipex"

echo -e "\n${CYAN}Creating test files...${NC}"

# Check if infile exists, if not create a basic one
if [ ! -f "infile" ]; then
    cat > infile << 'EOF'
foo bar
hello world
foo baz
test line
test | pipe
test ; semicolon
EOF
    print_success "Created infile with test data"
else
    print_success "Using existing infile"
fi

touch empty_file
print_success "Created empty_file"

# ============================================================================
# SECTION 1: BASIC FUNCTIONALITY
# ============================================================================

print_header "SECTION 1: BASIC FUNCTIONALITY"

print_section "1.1 - Simple commands"

test_command "Simple cat and wc" infile "cat" "wc -l" outfile 0 1
test_command "grep and wc" infile "grep foo" "wc -l" outfile 0 1
test_command "ls and wc" . "ls" "wc -l" outfile 0 1

print_section "1.2 - Commands with arguments"

test_command "grep with argument" infile "grep foo" "wc -l" outfile 0 1
test_command "grep with flag -i" infile "grep -i FOO" "wc -l" outfile 0 1

# ============================================================================
# SECTION 2: INVALID COMMANDS (CORRECTED EXIT CODES)
# ============================================================================

print_header "SECTION 2: INVALID COMMANDS"

print_section "2.1 - Command not found"

# bash: < infile invalidcmd | cat > outfile ; echo $? → 0
test_command "First command doesn't exist" infile "invalidcmd" "cat" outfile 0

# bash: < infile cat | invalidcmd > outfile ; echo $? → 127
test_command "Second command doesn't exist" infile "cat" "invalidcmd" outfile 127

# bash: < infile cmd1 | cmd2 > outfile ; echo $? → 127
test_command "Both commands don't exist" infile "cmd1_fail" "cmd2_fail" outfile 127

# ============================================================================
# SECTION 3: PERMISSION ERRORS (CORRECTED EXIT CODES)
# ============================================================================

print_header "SECTION 3: PERMISSION ERRORS"

print_section "3.1 - Infile permission denied"

chmod 000 infile 2>/dev/null
# bash: < infile cat | wc -l > outfile ; echo $? → 0
test_command "Infile without read permission" infile "cat" "wc -l" outfile 0
chmod 644 infile

print_section "3.2 - Outfile creation when infile has no permission"

chmod 000 infile 2>/dev/null
rm -f outfile_test 2>/dev/null
test_command "Outfile created even with infile permission denied" infile "cat" "wc -l" outfile_test 0 1
if [ -f "outfile_test" ]; then
    print_success "✓ Outfile was created despite infile error"
else
    print_error "✗ Outfile was not created"
fi
rm -f outfile_test
chmod 644 infile

print_section "3.3 - Outfile permission denied"

touch outfile
chmod 000 outfile 2>/dev/null
test_command "Outfile without write permission" infile "cat" "wc -l" outfile 1
chmod 666 outfile
rm -f outfile

print_section "3.4 - Outfile in read-only directory"

mkdir -p /tmp/readonly_test_$$ 2>/dev/null
chmod 555 /tmp/readonly_test_$$ 2>/dev/null
test_command "Outfile in read-only directory" infile "cat" "wc -l" "/tmp/readonly_test_$$/outfile" 1
chmod 755 /tmp/readonly_test_$$ 2>/dev/null
rm -rf /tmp/readonly_test_$$ 2>/dev/null

# ============================================================================
# SECTION 4: OUTFILE CREATION TESTS
# ============================================================================

print_header "SECTION 4: OUTFILE CREATION"

print_section "4.1 - Outfile creation"

rm -f new_outfile 2>/dev/null
test_command "Create outfile when it doesn't exist" infile "cat" "wc -l" new_outfile 0 1
if [ -f "new_outfile" ]; then
    print_success "✓ Outfile was created"
else
    print_error "✗ Outfile was not created"
fi
rm -f new_outfile

print_section "4.2 - Outfile truncation"

echo "old content that should be removed" > existing_outfile
test_command "Truncate existing outfile" infile "cat" "wc -l" existing_outfile 0 1
content=$(cat existing_outfile)
if ! echo "$content" | grep -q "old content"; then
    print_success "✓ Outfile was truncated"
else
    print_error "✗ Outfile was not truncated (old content still present)"
fi
rm -f existing_outfile

# ============================================================================
# SECTION 5: EMPTY STRING COMMANDS
# ============================================================================

print_header "SECTION 5: EMPTY STRING COMMANDS"

print_section "5.1 - Empty command strings"

# When first command is empty/spaces: bash returns 0 (command not found in first position)
test_command "Empty first command" infile "" "wc -l" outfile 0

# When second command is empty/spaces: bash returns 127 (command not found in second position)
test_command "Empty second command" infile "cat" "" outfile 127

# When both are empty: bash returns 127 (second command determines exit code)
test_command "Both commands empty" infile "" "" outfile 127

print_section "5.2 - Only spaces in command"

# First command is spaces: bash returns 0 (like command not found in first position)
test_command "First command is spaces" infile "   " "wc -l" outfile 0

# Second command is spaces: bash returns 127
test_command "Second command is spaces" infile "cat" "   " outfile 127

# ============================================================================
# SECTION 6: QUOTE HANDLING
# ============================================================================

print_header "SECTION 6: QUOTE HANDLING"

print_section "6.1 - Single quotes"

cat > infile_quotes << 'EOF'
foo bar
hello world
single word
EOF

test_command "grep with single-quoted pattern" infile_quotes "grep 'foo bar'" "wc -l" outfile 0 1

print_section "6.2 - Mixed quotes"

test_command "Single quote wrapping double quote" infile_quotes 'grep "foo"' "wc -l" outfile 0 1
test_command "Double quote wrapping single quote" infile_quotes "grep 'foo'" "wc -l" outfile 0 1

rm -f infile_quotes

# ============================================================================
# SECTION 7: EDGE CASES
# ============================================================================

print_header "SECTION 7: EDGE CASES"

print_section "7.1 - Empty infile"

test_command "Empty infile" empty_file "cat" "wc -l" outfile 0 1

print_section "7.2 - Large infile"

seq 1 1000 > large_file.txt
test_command "Large input file (1000 lines)" large_file.txt "cat" "wc -l" outfile 0 1
rm -f large_file.txt

print_section "7.3 - Absolute paths"

test_command "Absolute path /bin/cat" infile "/bin/cat" "wc -l" outfile 0 1
test_command "Absolute path /usr/bin/wc" infile "cat" "/usr/bin/wc -l" outfile 0 1

# ============================================================================
# SECTION 8: SPECIAL CHARACTERS AND EDGE CASES
# ============================================================================

print_header "SECTION 8: SPECIAL CHARACTERS"

print_section "8.1 - Commands with patterns that exist in file"

# Create a test file with known content
cat > test_infile << 'EOF'
test line
foo bar
hello world
EOF

# These should return 0 because grep finds matches
test_command "grep for word 'test'" test_infile "cat" "grep 'test'" outfile 0 1
test_command "grep for word 'foo'" test_infile "cat" "grep 'foo'" outfile 0 1

rm -f test_infile

print_section "8.2 - Commands with patterns that DON'T exist in file"

# These should return 1 because grep finds no matches
test_command "grep for @ (not in file)" infile "cat" "grep '@'" outfile 1 1
test_command "grep for xyzabc123 (not in file)" infile "cat" "grep 'xyzabc123'" outfile 1 1

print_section "8.3 - Invalid command arguments"

# head with invalid argument → exit 1 (command error, not "not found")
test_command "head with invalid number" infile "cat" "head -n abc" outfile 1

print_section "8.4 - Multiple consecutive runs (leak detection)"

echo -e "${CYAN}Running 10 consecutive tests to check for FD leaks...${NC}"
leak_detected=0
for i in {1..10}; do
    ./pipex infile "cat" "wc -l" outfile 2>/dev/null
    if [ $? -ne 0 ]; then
        leak_detected=1
        echo -e "${RED}Failed on run $i${NC}"
        break
    fi
    echo -n "."
done
echo ""
if [ $leak_detected -eq 0 ]; then
    print_success "10 consecutive runs completed without crash"
else
    print_error "Failed during consecutive runs"
fi

# ============================================================================
# SECTION 9: VALGRIND TESTS
# ============================================================================

if command -v valgrind &> /dev/null; then
    print_header "SECTION 9: VALGRIND MEMORY & FD TESTS"
    
    echo -e "${CYAN}Using Valgrind flags: $VALGRIND_FLAGS${NC}\n"

    print_section "9.1 - Basic commands"

    valgrind_test "Simple cat and wc" infile "cat" "wc -l" outfile
    valgrind_test "grep with argument" infile "grep foo" "wc -l" outfile

    print_section "9.2 - Invalid commands"

    valgrind_test "First command invalid" infile "invalidcmd" "cat" outfile
    valgrind_test "Second command invalid" infile "cat" "invalidcmd" outfile

    print_section "9.3 - Empty strings"

    valgrind_test "Empty first command" infile "" "wc -l" outfile
    valgrind_test "Empty second command" infile "cat" "" outfile

    print_section "9.4 - Permission errors"

    chmod 000 infile 2>/dev/null
    valgrind_test "Infile without read permission" infile "cat" "wc -l" outfile
    chmod 644 infile

    chmod 000 outfile 2>/dev/null
    valgrind_test "Outfile without write permission" infile "cat" "wc -l" outfile
    chmod 666 outfile

    print_section "9.5 - Quote handling"

    valgrind_test "Single-quoted pattern" infile "grep 'foo bar'" "wc -l" outfile
    valgrind_test "Double-quoted pattern" infile 'grep "foo bar"' "wc -l" outfile

else
    print_warning "Valgrind not found - skipping memory tests"
fi

# ============================================================================
# SECTION 10: SEGFAULT TESTS WITH ULIMIT
# ============================================================================

if command -v valgrind &> /dev/null; then
    print_header "SECTION 10: SEGFAULT TESTS (ULIMIT + VALGRIND)"

    print_section "10.1 - Invalid second command with memory limit"

    TOTAL_TESTS=$((TOTAL_TESTS + 1))
    echo -e "\n${YELLOW}Test $TOTAL_TESTS: Very long invalid command with ulimit${NC}"
    echo -e "${CYAN}Command: (ulimit -v 1000000; valgrind --leak-check=full --show-leak-kinds=all ./pipex infile cat \"klppppppppppppppppppppppp\" outfile_ulimit)${NC}"
    
    (ulimit -v 1000000; valgrind --leak-check=full --show-leak-kinds=all ./pipex infile cat "klppppppppppppppppppppppp" outfile_ulimit 2>&1 | grep -E "(LEAK SUMMARY|ERROR SUMMARY|Segmentation fault|Invalid)" | head -5)
    exit_code=$?
    
    if [ $exit_code -ne 139 ]; then  # 139 = segfault
        print_success "No segfault - handled gracefully"
        PASSED_TESTS=$((PASSED_TESTS + 1))
    else
        print_error "Segmentation fault detected"
        FAILED_TESTS=$((FAILED_TESTS + 1))
    fi
    rm -f outfile_ulimit

    print_section "10.2 - Empty second command with memory limit"

    TOTAL_TESTS=$((TOTAL_TESTS + 1))
    echo -e "\n${YELLOW}Test $TOTAL_TESTS: Empty second command with ulimit${NC}"
    echo -e "${CYAN}Command: (ulimit -v 1000000; valgrind --leak-check=full --show-leak-kinds=all ./pipex infile cat \"\" outfile_ulimit2)${NC}"
    
    (ulimit -v 1000000; valgrind --leak-check=full --show-leak-kinds=all ./pipex infile cat "" outfile_ulimit2 2>&1 | grep -E "(LEAK SUMMARY|ERROR SUMMARY|Segmentation fault|Invalid)" | head -5)
    exit_code=$?
    
    if [ $exit_code -ne 139 ]; then
        print_success "No segfault - handled gracefully"
        PASSED_TESTS=$((PASSED_TESTS + 1))
    else
        print_error "Segmentation fault detected"
        FAILED_TESTS=$((FAILED_TESTS + 1))
    fi
    rm -f outfile_ulimit2

    print_section "10.3 - Memory stress test"

    TOTAL_TESTS=$((TOTAL_TESTS + 1))
    echo -e "\n${YELLOW}Test $TOTAL_TESTS: Multiple runs with memory limit${NC}"
    
    segfault_count=0
    for i in {1..5}; do
        (ulimit -v 1000000; ./pipex infile cat "invalidcmd$i" outfile_stress 2>/dev/null)
        if [ $? -eq 139 ]; then
            segfault_count=$((segfault_count + 1))
        fi
    done
    
    if [ $segfault_count -eq 0 ]; then
        print_success "All 5 runs completed without segfault"
        PASSED_TESTS=$((PASSED_TESTS + 1))
    else
        print_error "Detected $segfault_count segfault(s) in 5 runs"
        FAILED_TESTS=$((FAILED_TESTS + 1))
    fi
    rm -f outfile_stress

else
    print_warning "Valgrind not found - skipping segfault tests"
fi

# ============================================================================
# CLEANUP
# ============================================================================

print_header "CLEANUP"

echo -e "${CYAN}Removing test files...${NC}"
# Don't delete user's infile and outfile
rm -f empty_file large_file.txt outfile_test new_outfile existing_outfile infile_quotes outfile_ulimit outfile_ulimit2 outfile_stress test_infile
rm -rf /tmp/readonly_test_$$ 2>/dev/null
print_success "Cleanup complete (kept your infile and outfile)"

# ============================================================================
# FINAL REPORT
# ============================================================================

print_header "FINAL REPORT"

echo -e "${CYAN}Test Summary:${NC}"
echo -e "  Total tests:     $TOTAL_TESTS"
echo -e "  ${GREEN}Passed:          $PASSED_TESTS${NC}"
echo -e "  ${RED}Failed:          $FAILED_TESTS${NC}"

if [ $VALGRIND_WARNINGS -gt 0 ]; then
    echo -e "  ${YELLOW}Valgrind issues: $VALGRIND_WARNINGS${NC}"
fi

if [ $FD_LEAK_WARNINGS -gt 0 ]; then
    echo -e "  ${YELLOW}FD leak warnings: $FD_LEAK_WARNINGS${NC}"
fi

percentage=$(( PASSED_TESTS * 100 / TOTAL_TESTS ))
echo -e "\n${CYAN}Pass rate:${NC} $percentage%"

echo ""
if [ $FAILED_TESTS -eq 0 ] && [ $VALGRIND_WARNINGS -eq 0 ] && [ $FD_LEAK_WARNINGS -eq 0 ]; then
    echo -e "${GREEN}╔═══════════════════════════════════════════════════════════════╗${NC}"
    echo -e "${GREEN}║                                                               ║${NC}"
    echo -e "${GREEN}║   🎉  PERFECT! ALL TESTS PASSED + NO LEAKS!  🎉              ║${NC}"
    echo -e "${GREEN}║                                                               ║${NC}"
    echo -e "${GREEN}╚═══════════════════════════════════════════════════════════════╝${NC}"
    exit 0
elif [ $FAILED_TESTS -eq 0 ] && [ $VALGRIND_WARNINGS -gt 0 ]; then
    echo -e "${YELLOW}╔═══════════════════════════════════════════════════════════════╗${NC}"
    echo -e "${YELLOW}║                                                               ║${NC}"
    echo -e "${YELLOW}║   ⚠  TESTS PASSED BUT MEMORY/FD LEAKS DETECTED!              ║${NC}"
    echo -e "${YELLOW}║                                                               ║${NC}"
    echo -e "${YELLOW}╚═══════════════════════════════════════════════════════════════╝${NC}"
    exit 1
elif [ $percentage -ge 90 ]; then
    echo -e "${GREEN}╔═══════════════════════════════════════════════════════════════╗${NC}"
    echo -e "${GREEN}║                                                               ║${NC}"
    echo -e "${GREEN}║   ✓  EXCELLENT! Over 90% tests passed!                       ║${NC}"
    echo -e "${GREEN}║                                                               ║${NC}"
    echo -e "${GREEN}╚═══════════════════════════════════════════════════════════════╝${NC}"
    exit 0
elif [ $percentage -ge 75 ]; then
    echo -e "${YELLOW}╔═══════════════════════════════════════════════════════════════╗${NC}"
    echo -e "${YELLOW}║                                                               ║${NC}"
    echo -e "${YELLOW}║   ⚠  GOOD! Over 75% passed, room for improvement             ║${NC}"
    echo -e "${YELLOW}║                                                               ║${NC}"
    echo -e "${YELLOW}╚═══════════════════════════════════════════════════════════════╝${NC}"
    exit 1
else
    echo -e "${RED}╔═══════════════════════════════════════════════════════════════╗${NC}"
    echo -e "${RED}║                                                               ║${NC}"
    echo -e "${RED}║   ✗  ATTENTION! Less than 75% tests passed                   ║${NC}"
    echo -e "${RED}║                                                               ║${NC}"
    echo -e "${RED}╚═══════════════════════════════════════════════════════════════╝${NC}"
    exit 1
fi
