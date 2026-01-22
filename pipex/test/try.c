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
    if (access(argv[1], F_OK) == -1)
        printf("Don't exist\n");
    else 
        printf("Exist\n");
    return (0);
}