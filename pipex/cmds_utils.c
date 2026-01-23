/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:02:22 by omawele           #+#    #+#             */
/*   Updated: 2026/01/23 15:07:10 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"



char *separate_cmd_flags(char *s)
{
	char **tmp;
	char *final;

	tmp = ft_split(s, ' ');
	if (!tmp)
		return (NULL);
	final = ft_strdup(tmp[0]);
	if (!final)
		return (free_tab(&tmp), NULL);
	return (free_tab(&tmp), final);
}

char *create_cmd(char *s)
{
	char *tmp;
    char *tmp2;
	char *final;

    tmp2 = NULL;
	tmp = ft_strtrim(s, " ");
	if (!tmp)
		return (NULL);
    if (count_words(tmp) > 1)
    {
        tmp2 = separate_cmd_flags(tmp);
        free(tmp);
        if (!tmp2)
            return (NULL);
        tmp = tmp2;
    }
	final = ft_strjoin("/bin/", tmp);
	if (!final)
		return (free(tmp), NULL);
	return (free(tmp), final);
}

// char **create_env(char *cmd, char *flags)
// {
//     char **tab;
//     char **tmp;
//     int cw;

//     cw = count_words(flags);
//     if (cw > 1)
//         tmp = ft_split(flags, ' ');   
// }