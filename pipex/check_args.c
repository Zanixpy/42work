/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:22:14 by omawele           #+#    #+#             */
/*   Updated: 2026/01/07 18:26:35 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int checking_file(char *filename, char *filename2)
{
    int fd;
    int fd2;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return (1);
    fd2 = open(filename2, O_RDONLY);
    if (fd2 == -1)
        return (close(fd), 2);
    return (close(fd), close(fd2), 0);
}