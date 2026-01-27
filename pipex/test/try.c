# include <fcntl.h>
# include <limits.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <errno.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "../libft/libft.h"

int main(int argc, char *argv[], char *envp[])
{
    // int *fds;
    // int buffer_file;


    if (access(argv[1], F_OK) == -1)
        printf("Doesnt exist\n");
    else
        printf("DOes exist");
    // if (pipe(fds) == -1)
    //     return 1;
    // buffer_file = open("buffer_file.txt", O_CREAT, 700 | 010 | 001);
    // if (buffer_file == -1)
    //     return (EXIT_FAILURE);
    
    // // int fd = open("salut", O_RDWR);
    // char *arg[] = {"/bin/cat", "-l", NULL};
    // // if (fd == -1)
    // //     return 1;
    // // int save_stdout = dup(1); 
    // // int new_fd = dup2(fd, 1);
    // // write(1, "Test 1\n", 7);
    // execve("/bin/ls", arg, envp);
    // // int test = dup2(save_stdout, new_fd);
    // // write(save_stdout, "Test 2\n", 7);
    // // printf("save_stdout : %d, fd : %d, test : %d, new_fd : %d", save_stdout, fd, test, new_fd);
    // // close(save_stdout);
    // // close(fd);
    return (0);
}