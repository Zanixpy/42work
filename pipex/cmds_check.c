/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 11:43:20 by omawele           #+#    #+#             */
/*   Updated: 2026/01/21 11:51:15 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	cmd_one_with_flags(char *cmd, char *envp[])
{
	char	**tab;
	char	*tmp;
	char	*final;

	tmp = create_cmd(cmd);
	if (!tmp)
		return (EXIT_FAILURE);
    tab = ft_split(tmp, ' ');
	if (!tab)
		return (free(tmp), EXIT_FAILURE);
	final = tab[0];
	free(tmp);
	execve_cmd(final, tab, envp);
	return (free_tab(&tab), EXIT_SUCCESS);
}

int	cmd_one_without_flags(char *cmd, int index, char *argv[], char *envp[])
{
    char    **env;
	char	*final;

	final = create_cmd(cmd);
	if (!final)
		return (EXIT_FAILURE);
    // ft_printf("final : %s\n", final);
	execve_cmd(final, argv, envp);
	return (free(final), EXIT_SUCCESS);
}

int	cmd_two_with_flags(char *argv[], char *envp[])
{
	char	**tab;
	char	*tmp;
	char	*final;

	tmp = create_cmd(argv[2]);
	if (!tmp)
		return (EXIT_FAILURE);
    tab = ft_split(tmp, ' ');
	if (!tab)
		return (free(tmp), EXIT_FAILURE);
	final = tab[0];
	free(tmp);
    // ft_printf("final : %s\n", final);
	execve_cmd(final, tab, envp);
	return (free_tab(&tab), EXIT_SUCCESS);
}

int	cmd_two_without_flags(char *argv[], char *envp[])
{
	char	*final;

	final = create_cmd(argv[2]);
	if (!final)
		return (EXIT_FAILURE);
    // ft_printf("final : %s\n", final);
	execve_cmd(final, argv, envp);
	return (free(final), EXIT_SUCCESS);
}
