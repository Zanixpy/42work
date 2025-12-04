/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:17:53 by omawele           #+#    #+#             */
/*   Updated: 2025/12/04 15:20:21 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <sys/time.h>

void free_mlx(t_window *mlx)
{
    mlx_destroy_display(mlx->init);
    free(mlx->init);
}

void free_player(t_player *p)
{
    mlx_
}

void free_textures(t_window *mlx);

