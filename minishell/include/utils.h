/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 02:55:21 by omawele           #+#    #+#             */
/*   Updated: 2026/03/26 00:58:24 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <string.h>
# include "../external/libft/libft.h"

# define TRUE 0
# define FALSE 1

#define GREAT '>'
#define GREATGREAT ">>"
#define LESS '<'
#define LESSLESS "<<"
#define PIPE '|'
#define NEWLINE '\n'
#define DOLLAR '$'
#define SPACE ' '
#define QUOTE 39
#define DQUOTE '"'


typedef struct s_cmd
{
    char    *path;          // Le chemin vers l'exécutable (/bin/ls)
    char    **args;         // Le tableau d'arguments
    char    *current_dir;   // Ton PWD au moment du lancement
    int     fdin;           // Pour les redirections <
    int     fdout;          // Pour les redirections >
    struct s_cmd *next;     // Si tu as des pipes
} t_cmd;


int is_space_tabs_null(char *s);




#endif