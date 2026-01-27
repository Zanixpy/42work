/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:13:24 by omawele           #+#    #+#             */
/*   Updated: 2026/01/27 17:53:02 by omawele          ###   ########.fr       */
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
    else if (code == EXIT_FAIL_FORK)
        ft_putstr_fd("fork: an error occured\n", 2);
    else if (code == EXIT_FAIL_PIPE)
        ft_putstr_fd("pipe: an error occured\n", 2);
    return (code);
}

int pipex(char **argv, char **envp, int buffer_fd)
{
    int *fds;
    int fd2;
    int buffer_result;    

    fds = create_fds();
    if (!fds)
        return (EXIT_FAILURE);
    if (pipe(fds) == -1)
        return (free(fds), EXIT_FAIL_PIPE);
    fd2 = open_fd(argv[4], O_WRONLY);
    if (fd2 == EXIT_FAIL_OPEN)
        return (close(fd2), free(fds), EXIT_FAIL_OPEN);
    if (execute_first_cmd(fds, argv, envp) == EXIT_FAILURE)
        return (close(fd2), free(fds), EXIT_FAILURE);
    buffer_result = buffer_pipe(fds, buffer_fd);
    if (buffer_result)
        return (close(fd2), free(fds), EXIT_FAILURE);
    close(buffer_fd);
    buffer_fd = create_buffer_file();
    if (!buffer_fd)
        return (close(fd2), free(fds), EXIT_FAILURE);
    if (execute_second_cmd(fd2, argv, envp) == EXIT_FAILURE)
        return (close(fd2), free(fds), EXIT_FAILURE);
    return (close(fd2), free(fds), EXIT_SUCCESS);
}

int main(int argc, char **argv, char **envp)
{
    int carg;
    int result;
    int buffer_fd;
    
    if (argc != 5)
        return (print_errors(EXIT_FAIL_ARGS));
    carg = args_validation(argv);
    if (carg)
        return (print_errors(carg));
    buffer_fd = create_buffer_file();
    if (buffer_fd == EXIT_FAILURE)
        return (print_errors(buffer_fd));
    result = pipex(argv, envp, buffer_fd);
    if (result)   
        return (delete_file(buffer_fd), print_errors(result)); 
    return (delete_file(buffer_fd), EXIT_SUCCESS);
}
