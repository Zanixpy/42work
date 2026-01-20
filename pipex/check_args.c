/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:22:14 by omawele           #+#    #+#             */
/*   Updated: 2026/01/20 18:05:22 by omawele          ###   ########.fr       */
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

int checking_cmds(char *argv[], char *envp[])
{
    int result_cmd;
    int result_cmd2;
    
    result_cmd = 0;
    result_cmd2 = 0;

    return (result_cmd + result_cmd2);       
}

int check_args(char *argv[], char *envp[])
{
    if (checking_file(argv[1], argv[4]))
        return (2);
    if (checking_cmds(envp, argv))
        return (3);
    return (EXIT_SUCCESS);
}