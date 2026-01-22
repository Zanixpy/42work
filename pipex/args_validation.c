/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:22:14 by omawele           #+#    #+#             */
/*   Updated: 2026/01/22 13:22:12 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int check_first_file(char *filename1)
{
    int fd1;
    
    fd1 = open(filename1, O_RDONLY);
    if (fd1 == -1)
        return (EXIT_FAIL_OPEN);
    if (access(filename1, R_OK) == -1);
        return (close(fd1), EXIT_FAIL_PERM);
    return (close(fd1), EXIT_SUCCESS);
}

int check_second_file(char *filename2)
{
    int fd2;
    
    fd2 = open(filename2, O_WRONLY);
    if (fd2 > 2)
    {
        if (access(filename2, W_OK) == -1);
            return (close(fd2), EXIT_FAIL_PERM);
        return (close(fd2), EXIT_SUCCESS);
    }
    fd2 = open(filename2, O_CREAT, 00200);
    if (fd2 == -1)
        return (EXIT_FAIL_OPEN);    
    return (close(fd2), EXIT_SUCCESS);
}

int check_first_cmd(char *cmdname1, char **envp)
{
    
}

int check_second_cmd(char *cmdname2, char **envp)
{
    
}


int check_args(char *argv[], char *envp[])
{
    if (checking_file(argv[1], argv[4]))
        return (2);
    if (checking_cmds(argv, envp))
        return (3);
    return (EXIT_SUCCESS);
}