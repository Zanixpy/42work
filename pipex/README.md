# PIPEX (42)

## Workflow

### Understanding the issue

**Understanding** :To start with, a pipe is a file descriptor mostly like a buffer. Firstly, the pipe will read the content of the infile and stores his content executed by the first command. Secondly, it will give the other command the current content of the file for executing it and writes the result in the outfile. 

**Identify bordeline cases** :

- infile is empty
- infile is too large
- cmd1 doesnt't exist
- cmd2 doesnt't exist
- permission to read for infile is denied
- permission to write for outfile is denied

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