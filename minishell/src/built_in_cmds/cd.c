/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 22:00:52 by omawele           #+#    #+#             */
/*   Updated: 2026/02/26 22:53:56 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/built_in_cmds.h"
#include <stdlib.h>


static int is_path_valid(char *path)
{
    if (access(path, W_OK) == -1)
        return (error_handler(), FALSE);
}

int cd(char *path)
{
    if (is_path_valid(path))
        exit(FALSE);
    if (chdir(path) == -1)
        (error_handler(), exit(FALSE));
    exit(TRUE);
}