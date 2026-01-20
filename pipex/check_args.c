/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:22:14 by omawele           #+#    #+#             */
/*   Updated: 2026/01/19 16:16:22 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int checking_file(char *filename, char *filename2)
{
    int fd;
    int fd2;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return (EXIT_FAILURE);
    fd2 = open(filename2, O_RDONLY);
    if (fd2 == -1)
        return (close(fd), EXIT_FAILURE);
    return (close(fd), close(fd2), EXIT_SUCCESS);
}

int child_first_cmd_check(char *argv[], char *envp[])
{
    int status;
    pid_t pid;

    pid = fork();
    if (pid == -1)
        return (EXIT_FAILURE);
    else if (pid == 0)
    {
        
    }
    else if (pid > 0)
        waitpid(pid, &status, 0);


    
}

int child_second_cmd_check(char *argv[], char *envp[])
{
    int status;
    pid_t pid;

    pid = fork();
      if (pid == -1)
        return (EXIT_FAILURE);
    else if (pid == 0)
        child_cmds_check();
    else if (pid > 0)    
}



int checking_cmds(char *argv[], char *envp[])
{
        
    return (0);
}

int check_args(char *argv[], char *envp[])
{
    if (checking_file(argv[1], argv[4]))
        return (2);
    if (checking_cmds(envp, argv))
        return (3);
    return (EXIT_SUCCESS);
}