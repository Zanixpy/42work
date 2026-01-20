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
    int words_count;

    words_count = count_words(argv[1]);
    if (words_count == 1)
        cmd_one_without_flags(argv, envp);
    else if(words_count > 1)
        cmd_one_with_flags(argv, envp);
    return (0);
}