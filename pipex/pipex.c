/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:13:24 by omawele           #+#    #+#             */
/*   Updated: 2026/01/22 16:49:38 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int print_errors(int code)
{
    if (code == EXIT_FAILURE)
        ft_putstr_fd("error: fault occured somewhere\n", 2);
    else if (code == EXIT_FAIL_ARGS)
        ft_putstr_fd("args: more or less than 4\n", 2);
    else if (code == EXIT_FAIL_OPEN)
        ft_putstr_fd("open: couldn't open the file\n", 2);
    else if (code == EXIT_FAIL_CMD)
        ft_putstr_fd("command: not found\n", 2);
    else if (code == EXIT_FAIL_PERM)
        ft_putstr_fd("file: permission denied for writing or reading\n", 2);
    return (code);
}

int pipex(char **argv, char **envp)
{
    int *fds;

    (void)envp;
    fds = create_fds(argv[1], argv[4], O_RDONLY, O_WRONLY);
    if (!fds)
        return (EXIT_FAILURE);
    return (free(fds), EXIT_SUCCESS);
}

int main(int argc, char **argv, char **envp)
{
    int carg;
    int result;
    
    if (argc != 5)
        return (print_errors(EXIT_FAIL_ARGS));
    carg = args_validation(argv);
    if (carg)
        return (print_errors(carg));
    result = pipex(argv, envp);
    if (result)
        return (print_errors(result)); 
    return (EXIT_SUCCESS);
}
