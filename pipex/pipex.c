/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:13:24 by omawele           #+#    #+#             */
/*   Updated: 2026/01/19 14:14:40 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void print_errors(int code)
{
    write(2, "Error\n", 7);
    if (code == 1)
        write(2, "More or less than 4 arguments", 29);
    else if (code == 2)
        perror("Open");
    else if (code == 3)
        perror("Command");
}


int main(int argc, char *argv[], char *envp[])
{
    int carg;
    
    if (argc != 5)
        return (print_errors(1), EXIT_FAILURE);
    carg = check_args(argv, envp);
    

    return (EXIT_SUCCESS);
}
