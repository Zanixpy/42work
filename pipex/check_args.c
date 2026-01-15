/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:22:14 by omawele           #+#    #+#             */
/*   Updated: 2026/01/15 15:20:10 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int checking_file(char *filename, char *filename2)
{
    int fd;
    int fd2;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return (2);
    fd2 = open(filename2, O_RDONLY);
    if (fd2 == -1)
        return (close(fd), 2);
    return (close(fd), close(fd2), 0);
}

int checking_cmds(char *envp[], char *cmd1, char *cmd2)
{
    return (0);
}

int check_args(char *argv[], char *envp[])
{
    if (checking_file(argv[1], argv[4]))
        return (2);
    if (checking_cmds(envp, argv[2], argv[3]))
        return (3);
    return (0);
}