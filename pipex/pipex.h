/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:13:42 by omawele           #+#    #+#             */
/*   Updated: 2026/01/30 13:07:26 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# define EXIT_FAIL_ARGS 00200
# define EXIT_FAIL_OPEN 00300
# define EXIT_FAIL_CMD 00400
# define EXIT_FAIL_PERM 00500
# define EXIT_FAIL_PIPE 00600
# define EXIT_FAIL_FORK 00700

// Main function

int		pipex(char **argv, char **envp);

// Pipex utils

char	**create_env_with_flags(char *cmd, char *original_cmd);
char	**create_env_without_flags(char *cmd);
int		execute_first_cmd(int *fds, int fd1, char **argv, char **envp);
int		execute_second_cmd(int *fds, int fd2, char **argv, char **envp);

// Arguments Validation

int		args_validation(char **argv, char **env);

// Files utils

int		open_fd(char *filename, int mode);
void	close_fds(int fd1, int fd2);
int		*create_fds(void);
int		change_stdin_out(int std_fd, int fd);
void	restore_stdin_out(int save_std_fd, int fd);

// Cmds utils

char	*create_cmd(char *cmd, char **env);
int		execve_cmd(char *cmd, char *argv[], char *envp[]);
char	*get_path(char **env);
char	*search_path(char **path, char *cmd);
char	*find_path(char *cmd, char **env);

// Functs utils

int		count_words(char *s);
void	free_tab(char ***tab);
void	free_tab_index(char ***tab, int x);
char	**create_tab_with_flags(char *cmd, char **flags, int size_flags);

#endif