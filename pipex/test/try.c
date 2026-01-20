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
# include "libft/libft.h"

char *create_bin_cmd(char *cmd, char **tab)
{
    char *bin;

    if (tab)
        bin = ft_strjoin("/bin/", tab[0]);
    else
        bin = ft_strjoin("/bin/", cmd);
    if (!bin)
        return (NULL);
    return (bin);
}

char *create_usr_bin_cmd(char *cmd, char **tab)
{
    char *usr_bin;

    if (tab)
        usr_bin = ft_strjoin("/usr/bin/", tab[0]);
    else
        usr_bin = ft_strjoin("/usr/bin/", cmd);
    if (!usr_bin)
        return (NULL);
    return (usr_bin);
}

char **arrange_cmd(char *cmd)
{
    char **tab;

    tab = ft_split(cmd, ' ');
    if (!tab)
        return (NULL);
    return (tab);
}

int execve_cmd(char **bin_cmd, char **usr_bin_cmd, char ***tab, )
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1)
        perror("Issues");
    else if (pid == 0)
    {
        if (execve("ls", argv, envp) == -1)
            perror("Execve");
        if ()
        exit(3);
    }
    else if (pid > 0)
    {
        waitpid(pid, &status, 0);
        if (WIFEXITED(status))
        {
            if (WEXITSTATUS(status) == 3)
                return (free()3);
        }
    }
    return (EXIT_SUCCESS);
}

int cmd_one(char *argv[], char *envp[])
{
    char **tab;
    char *cmd;
    char *bin_cmd;
    char *usr_bin_cmd;

    cmd = ft_strtrim(argv[2], " ");
    if (!cmd)
        return (1);
    tab = arrange_cmd(cmd);
    if (tab)
        argv[2] = tab[1];
    bin_cmd = create_bin_cmd(cmd, tab);
    if (!bin_cmd && tab)
        return (free(cmd), free(tab), 1);
    else if (!bin_cmd)
        return (free(cmd), 1);
    usr_bin_cmd = create_usr_bin_cmd(cmd, tab);
    if (!usr_bin_cmd && tab)
        return (free(cmd), free(tab), free(bin_cmd), 1);
    else if (!usr_bin_cmd)
        return (free(cmd), free(bin_cmd), 1);
    execve_cmd()
    return (0);
}

int main(int argc, char *argv[], char *envp[])
{
    int i = 0;

    while (envp[i])
    {
        printf("%s\n",envp[i]);
        i++;
    }
    
    cmd_one(argv, envp);
    return (0);
}