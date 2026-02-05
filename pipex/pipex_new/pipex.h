/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:13:42 by omawele           #+#    #+#             */
/*   Updated: 2026/02/05 12:44:07 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# define EXIT_FAIL_ARGS 00200
# define EXIT_FAIL_DUP 00300
# define EXIT_FAIL_FIRST_FILE 00400
# define EXIT_FAIL_SEC_FILE 00500
# define EXIT_FAIL_EXECVE 00600
# define EXIT_FAIL_FORK 00700
# define EXIT_FAIL_PIPE 127

// Main function

int		pipex(char **argv, char **envp);

// Pipex utils

char **create_env(char *cmd, char *original_cmd);
char	**create_env_with_flags(char *cmd, char *original_cmd);
char	**create_env_without_flags(char *cmd);
int launch_first_child(int *fds, char **argv, char **envp);
int launch_second_child(int *fds, char **argv, char **envp);

// Arguments Validation

int	args_validation(int argc, char **argv, char **env);
int	check_first_file(char *filename1);
int	check_second_file(char *filename2);

// Files utils

int		open_fd(char *filename, int mode);
void	close_fds(int fd1, int fd2);
int		*create_fds(void);
int		change_stdin_out(int std_fd, int fd);
void	restore_stdin_out(int save_std_fd, int fd, int save_std_fd2, int fd2);

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
void free_malloc(char **cmd, char ***env);
char	**create_tab_with_flags(char *cmd, char **flags, int size_flags);

#endif