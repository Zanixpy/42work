/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 21:10:17 by omawele           #+#    #+#             */
/*   Updated: 2025/12/16 16:40:33 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_coins_textures(t_var *var)
{
    if (!var->t.coins.c1)
        return (1);
    if (!var->t.coins.c2)
        return (2);
    if (!var->t.coins.c3)
        return (3);
    if (!var->t.coins.c4)
        return (4);
    if (!var->t.coins.c5)
        return (5);
    if (!var->t.coins.c6)
        return (6);
    if (!var->t.coins.c7)
        return (7);
    if (!var->t.coins.c8)
        return (8);
    return (0);
}

int check_textures(t_var *var)
{
    if (!var->t.player_up)
        return (1);
    if (!var->t.player_down)
        return (2);
    if (!var->t.player_right)
        return (3);
    if (!var->t.player_left)
        return (4);
    if (!var->t.space)
        return (5);
    if (!var->t.wall)
        return (6);
    if (!var->t.exit_game)
        return (7);
    if (!var->t.lava)
        return (8);
    return (0);
}

int is_textures_valid(t_var *var)
{
    int ctextures;
    int ccoins_textures;

    load_textures(var);
    load_coins_textures(var);
    ctextures = check_textures(var);
    ccoins_textures = check_coins_textures(var);
    if (ctextures || ccoins_textures)
    {
        free_img_textures(var);
        free_img_coins_textures(var);
        return (1);
    }
    return (0);
}
