/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 01:53:22 by omawele           #+#    #+#             */
/*   Updated: 2026/03/30 22:35:36 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include <readline/readline.h>
#include <readline/history.h>


char *env;

#define NONE "NONE"

typedef struct s_cmd
{
    char    *cmd;          
    char    *path;          // Le chemin vers l'exécutable (/bin/ls)
    char    **args;         // Le tableau d'arguments
    char    *current_dir;   // Ton PWD au moment du lancement
    int     fdin;           // Pour les redirections < | <<
    int     fdout;          // Pour les redirections > | >>
    struct s_cmd *next;     // Si tu as des pipes
} t_cmd;

void test(t_cmd *cmd)
{
    cmd->path = NULL;
}

int main(void)
{
    // char *buf;
    t_cmd *cmd;
    char *try;
    cmd = malloc(sizeof(t_cmd));
    if (!cmd)
        return 1;

    // free(buf);
    test(cmd);
    if (cmd->path)
        printf("%s\n", cmd->path);
    // env = getenv("PATH");
    // printf("%s\n", env);
    free(cmd);
    return 0;
}
