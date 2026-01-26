/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 12:47:19 by omawele           #+#    #+#             */
/*   Updated: 2026/01/26 16:45:17 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int execute_first_cmd(int *fds, char **argv, char **envp)
{
    char **env;
    char *cmd;
    int save_stdout;
    int new_fd;

    cmd = create_cmd(argv[2]);
    if (!cmd)
        return (EXIT_FAILURE);
    if (count_words(argv[2]) > 1)
        env = create_env_with_flags(cmd, argv[2], argv[1]);
    else
        env = create_env_without_flags(cmd, argv[1]);
    if (!env)
        return (free(cmd), EXIT_FAILURE);
    save_stdout = dup(1);
    new_fd = dup2(fds[1], 1);
    if (execve_cmd(cmd, env, envp) == EXIT_FAILURE)
    {
        dup2(save_stdout, new_fd);
        return (free(cmd), free_tab(&env), close(save_stdout), EXIT_FAIL_FORK);
    }
    dup2(save_stdout, new_fd);
    return (free(cmd), free_tab(&env), EXIT_SUCCESS);   
}

int execute_second_cmd(int *fds, char **argv, char **envp)
{
    char **env;
    char *cmd;
    int save_stdout;
    int new_fd;

    cmd = create_cmd(argv[4]);
    if (!cmd)
        return (EXIT_FAILURE);
    if (count_words(argv[4]) > 1)
        env = create_env_with_flags(cmd, argv[2], argv[1]);
    else
        env = create_env_without_flags(cmd, argv[1]);
    if (!env)
        return (free(cmd), EXIT_FAILURE);
    save_stdout = dup(1);
    new_fd = dup2(fds[1], 1);
    if (execve_cmd(cmd, env, envp) == EXIT_FAILURE)
        return (free(cmd), free_tab(&env), close(save_stdout), EXIT_FAIL_FORK);
    dup2(save_stdout, new_fd);
    // close(save_stdout);
    return (free(cmd), free_tab(&env), EXIT_SUCCESS);   
}





