/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 11:03:38 by omawele           #+#    #+#             */
/*   Updated: 2026/01/27 16:42:05 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_tab(char ***tab)
{
	int	i;

	i = 0;
	while ((*tab)[i])
	{
		free((*tab)[i]);
		i++;
	}
	free((*tab));
}

void	free_tab_index(char ***tab, int x)
{
	while (--x)
		free((*tab)[x]);
	free((*tab));
}
