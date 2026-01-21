/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:22:14 by omawele           #+#    #+#             */
/*   Updated: 2026/01/21 11:30:56 by omawele          ###   ########.fr       */
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
    int cmd_words;
    int cmd_words2;

    cmd_words = count_words(argv[2]);
    cmd_words2 = count_words(argv[3]);
    result_cmd = 0;
    result_cmd2 = 0;
    // ft_printf("cw : %d, cw2 : %d\n", cmd_words, cmd_words2);   
    if (cmd_words == 1)
        result_cmd = cmd_one_without_flags(argv, envp);
    else if (cmd_words > 1)
        result_cmd = cmd_one_with_flags(argv, envp);
    if (cmd_words2 == 1)
        result_cmd2 = cmd_one_without_flags(argv, envp);
    else if (cmd_words2 > 1)
        result_cmd2 = cmd_one_with_flags(argv, envp);
    // ft_printf("result : %d, result2 : %d\n", result_cmd, result_cmd2);   
    return (result_cmd + result_cmd2);       
}

int check_args(char *argv[], char *envp[])
{
    if (checking_file(argv[1], argv[4]))
        return (2);
    if (checking_cmds(argv, envp))
        return (3);
    return (EXIT_SUCCESS);
}