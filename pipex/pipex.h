 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:13:42 by omawele           #+#    #+#             */
/*   Updated: 2026/02/16 01:34:54 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# define EXIT_FAIL_CMD2 127

// Main function

int		pipex(char **argv, char **envp);

// Pipex utils

char	**create_env_with_flags(char *cmd, char *original_cmd);
char	**create_env_without_flags(char *cmd);
char	**create_env(char *cmd, char *original_cmd);
int		execute_first_cmd(int *fds, char **argv, char **envp);
int		execute_second_cmd(int *fds, char **argv, char **envp);

// Arguments Validation

int		args_validation(int argc);
int		check_first_file(char *filename1);
int		check_second_file(char *filename2);

// Files utils

int		change_stdin_out(int fd1, int fd2);

// Cmds utils

char	*create_cmd(char *cmd, char **env);
char	*get_path(char **env);
char	*search_path(char **path, char *cmd);
char	*find_path(char *cmd, char **env);

// Functs utils

int		count_words(char *s);
void	free_tab(char ***tab);
void	free_tab_index(char ***tab, int x);
char	**create_tab_with_flags(char *cmd, char **flags, int size_flags);
void	print_error(char *msg);

#endif