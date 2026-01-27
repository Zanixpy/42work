/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:13:42 by omawele           #+#    #+#             */
/*   Updated: 2026/01/27 17:44:42 by omawele          ###   ########.fr       */
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

int pipex(char **argv, char **envp, int buffer_fd);

// Pipex utils

char **create_tab_with_flags(char *cmd, char **flags, char *filename, int size_flags);
char **create_env_with_flags(char *cmd, char *original_cmd, char *filename1);
char **create_env_without_flags(char *cmd, char *filename1);
int execute_first_cmd(int *fds, char **argv, char **envp);
int execute_second_cmd(int fd2, char **argv, char **envp);

// Buffer file utils

int create_buffer_file(void);
int write_on_buffer(int wr_fd, int rd_fd);
int delete_file(int fd);
int	buffer_pipe(int *fds, int buffer_fd);

// Arguments Validation 

int args_validation(char *argv[]);

// Files utils

int open_fd(char *filename, int mode);
void close_fds(int fd1, int fd2);
int *create_fds(void);

// Cmds utils

char *create_cmd(char *s);
int	execve_cmd(char *cmd, char *argv[], char *envp[]);

// Functs utils

int count_words(char *s);
void free_tab(char ***tab);
void free_tab_index(char ***tab, int x);
void print_file(int fd);


#endif