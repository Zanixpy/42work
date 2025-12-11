/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_unit_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 18:08:24 by omawele           #+#    #+#             */
/*   Updated: 2025/12/11 16:20:12 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <string.h>

static void set_checker(t_var *var)
{
    var->cmap.collectible = 0;
    var->cmap.player = 0;
    var->cmap.wall = 0;
    var->cmap.space = 0;
    var->cmap.exit_game = 0;
    var->cpath.valid_path = 0;
}

int     is_map_valid(t_var *var)
{
    set_checker(var);
    if (!check_map_size(var))
        return (1);
    if (!check_map_characters(var))
        return (2);
    check_map_path(var);
    if (!var->cpath.valid_path)
        return (3);
    return (0);
}





