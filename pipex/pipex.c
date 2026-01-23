/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:13:24 by omawele           #+#    #+#             */
/*   Updated: 2026/01/23 14:45:28 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/libft.h"

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
    else if (code == EXIT_FAIL_FORK)
        ft_putstr_fd("fork: an error occured\n", 2);
    else if (code == EXIT_FAIL_PIPE)
        ft_putstr_fd("pipe: an error occured\n", 2);
    return (code);
}

int pipex(char **argv, char **envp)
{
    int *fds;
    int fd1;
    int fd2;    
    int id;

    fds = create_fds();
    if (!fds)
        return (EXIT_FAILURE);
    if (pipe(fds) == -1)
        return (free(fds), EXIT_FAIL_PIPE);
    fd1 = open_fd(argv[1], O_RDONLY);
    fd2 = open_fd(argv[4], O_WRONLY);
    if (fd1 == EXIT_FAIL_OPEN || fd2 == EXIT_FAIL_OPEN)
        return (close_fds(fd1, fd2), free(fds), EXIT_FAIL_OPEN);
    id = fork();
    if (id == -1)
        return (close_fds(fd1, fd2), free(fds), EXIT_FAIL_FORK);
    else if (id == 0)
    {
        
    }
    else
    return (close_fds(fd1, fd2), free(fds), EXIT_SUCCESS);
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
