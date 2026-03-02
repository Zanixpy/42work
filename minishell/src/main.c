/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 03:06:56 by omawele           #+#    #+#             */
/*   Updated: 2026/02/27 23:10:59 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/minishell.h"
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

int main(void)
{
    t_cmd *cmd;
    char *prompt;

    prompt = readline(cw);
    while (prompt) 
    {
        if (!check_prompt(prompt))
        free(prompt);
        prompt = readline(cw);
    }  
    return 0;  
}
