/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:13:24 by omawele           #+#    #+#             */
/*   Updated: 2026/01/15 15:24:09 by omawele          ###   ########.fr       */
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
        return (1);
    carg = check_args(argv, envp);
    int i = 0;
    while (envp[i])
    {
        if (ft_strnstr(envp[i], "PATH", 4))
            printf("%s\n", envp[i]);
        i++;
    }
    return 0;
}
