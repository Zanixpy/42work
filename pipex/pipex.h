/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:13:42 by omawele           #+#    #+#             */
/*   Updated: 2026/01/22 11:55:41 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# define EXIT_FAIL_ARGS 2
# define EXIT_FAIL_OPEN 3
# define EXIT_FAIL_CMD 4
# define EXIT_FAIL_PERM 5

// Checkings arguments

int check_args(char *argv[], char *envp[]);
int	cmd_one_with_flags(char *argv[], char *envp[]);
int	cmd_one_without_flags(char *argv[], char *envp[]);
char *create_cmd(char *s);
int	execve_cmd(char *cmd, char *argv[], char *envp[]);

// Functs utils

int count_words(char *s);
void free_tab(char ***tab);



#endif