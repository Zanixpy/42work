/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 03:06:56 by omawele           #+#    #+#             */
/*   Updated: 2026/03/26 15:28:21 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *env;

char *get_prompt_line(void)
{
    char *prompt_line;
    char *cur_dir;

    cur_dir = ft_calloc(100, sizeof(char));
    if (!cur_dir)
        return (NULL);
    if (!getcwd(cur_dir, 100))
        return (free(cur_dir), NULL);
    prompt_line = ft_strjoin(cur_dir, "# ");
    if (!prompt_line)
        return (free(cur_dir), NULL); 
    return (prompt_line);
}

int main(int argc, char **argv)
{
    t_cmd *cmd;
    // char *prompt;
    // char *cw;
    char **tokens;
 
    (void)cmd;
    (void)argc;
    // cw = get_prompt_line();
    // prompt = readline(cw);
    tokens = lexer(argv[1]);
    int i = 0;
    while (tokens[i]) 
    {
        printf("%s\n", tokens[i]);
        i++;
    }
    free_char_tab(&tokens, i - 1);
    return 0;  
}
