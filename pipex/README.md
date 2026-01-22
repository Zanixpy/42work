# PIPEX (42)

## Workflow

### Understanding the issue

**Understanding** : To start with, a pipe is a file descriptor mostly like a buffer. Firstly, the pipe will read the content of the infile and stores his content executed by the first command. Secondly, it will give the other command the current content of the file for executing it and writes the result in the outfile. 

## Identify bordeline cases :

- infile is empty
- infile is too large
- cmd1 doesnt't exist
- cmd2 doesnt't exist
- permission to read for infile is denied
- permission to write for outfile is denied

## Identify input/output :
```
Input : 
- Type : [char *] * 4
- Description : two filenames (the first one must exist), two shell commands
- Validation : open first file and check if we have permission of reading it, open second file (if it doesn't we create it) and check if we have permission of writing in it, execute both command and see if there are errors

Output :
- Type : [void]
- Description : the function returns nothing but only change the content of the second file by the content of the first file transformed by both commands-line
- Errors code : EXIT_FAILURE, EXIT_FAIL_OPEN, EXIT_FAIL_CMD, EXIT_FAIL_ARGS, EXIT_FAIL_PERM
```

## Break down into sub-problems
```
Main issue : Doing the pipe concept
├── Sub-problem 1 : Verifying the arguements
│   ├── args_validation
│       ├── check_first_file 
|       ├── check_second_file
|       ├── check_first_cmd
|           ├── clean_cmd
|           ├── execute_cmd
│       └── check_second_cmd
├── Sub-problem 2 : Storing in pipe file the result of 1st shell cmd
│   ├── change_stdin
│   ├── putback_stdin 
│   └── execute_first_cmd 
├── Sub-problem 3 : Storing in pipe file the result of 2nd shell cmd
│   ├── change_stdin
│   ├── putback_stdin
│   └── execute_second_cmd 
├── Sub-problem 4 : Writing the content of pipe file in 2nd file
│   ├── write_in_file
└── END   
```

## Define the Data Structures 
```
Function args_validation :
- char **argv : list of given arguments  
- char **envp : the env for executing function

Function check_first_file :
- char *filename1 : represent the name of the first file

Function check_second_file :
- char *filename2 : represent the name of the second file

Function check_cmds :
- char *cmdname1 : represent the name of the 1st shell command
- char *cmdname2 : represent the name of the 1st shell command


Locals variable :
- int fd1 : represent the file descriptor of the first file
- int fd2 : represent the file descriptor of the second file
- char *shell_cmd1 : represent the first shell command
- char *shell_cmd2 : represent the second shell command

```

## Design algorithms (pseudo-code)
```
Function args_validation :
IF check_first_file :
    RETURN EXIT_FAIL_OPEN
IF check_second_file :
    RETURN EXIT_FAIL_OPEN
IF check_first_cmd :
    RETURN EXIT_FAIL_CMD
IF check_second_cmd :
    RETURN EXIT_FAIL_CMD
RETURN EXIT_SUCCESS

Function check_first_file :

IF FD1 == -1 :
    RETURN EXIT_FAIL_OPEN
IF access(FD1) :
    RETURN EXIT_FAIL_PERM
RETURN EXIT_SUCCESS

Function check_second_file :

IF FD2 > 2 :
    IF access(FD2) :
        RETURN EXIT_FAIL_PERM
CREATE THE FILE
IF FD2 == -1 :
    RETURN EXIT_FAIL_OPEN
RETURN EXIT_SUCCESS

Function check_cmds:
clean_cmd
IF execute_cmd :
    RETURN EXIT_FAIL_CMD
RETURN EXIT_SUCCESS




```

## External functs.

- open
- close
- read
- write
- malloc
- free
- perror
- strerror
- access
- dup
- dup2
- execve
- exit
- fork
- pipe
- unlink
- wait
- waitpid

## Check to do

< infile cmd1 | wc > file2
cmd1: command not found

< infile ls | cmd2 > file2
cmd2: command not found

< file1 ls | cmd2 > file2 or  < file1 cmd1 | cmd2 > file2
bash: file1: No such file or directory
cmd2: command not found

< infile ls | cmd2 > file2
bash: infile: Permission denied
cmd2: command not found