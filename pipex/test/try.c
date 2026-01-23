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
    int fd = open("salut", O_RDWR);
    char *arg[] = {"/bin/ls", "-l", NULL};
    if (fd == -1)
        return 1;
    int save_stdout = dup(1); 
    int new_fd = dup2(fd, 1);
    write(1, "Test 1\n", 7);
    execve("/bin/ls", arg, envp);
    int test = dup2(save_stdout, new_fd);
    write(1, "Test 2\n", 7);
    printf("save_stdout : %d, fd : %d, test : %d, new_fd : %d", save_stdout, fd, test, new_fd);
    close(save_stdout);
    close(fd);
    return (0);
}