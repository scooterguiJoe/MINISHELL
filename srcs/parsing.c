/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scootergui <scootergui@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 21:41:34 by scootergui        #+#    #+#             */
/*   Updated: 2025/11/14 16:36:32 by scootergui       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
# include <readline/readline.h>
# include <readline/history.h>

int main(void)
{
	char *line;

	while(1)
	{
		setup_signals();
		line = readline("minishell > ");
		if(!line)
			break;
		if(*line)
			add_history(line);
		printf("Input: %s\n", line); //debug
		free(line);
	}
	return (0);
}
/*void print_tokens(t_token *list)
{
    while (list)
    {
        printf("TYPE: %d | VALUE: %s\n", list->type, list->value);
        list = list->next;
    }
}

int main(void)
{
    t_token *list = NULL;

    ft_addtoken(&list, ft_newtoken(WORD, strdup("echo")));
    ft_addtoken(&list, ft_newtoken(WORD, strdup("hello")));
    ft_addtoken(&list, ft_newtoken(PIPE, strdup("|")));
    ft_addtoken(&list, ft_newtoken(WORD, strdup("ls")));
    ft_addtoken(&list, ft_newtoken(REDIR_OUT, strdup(">")));
    ft_addtoken(&list, ft_newtoken(WORD, strdup("file.txt")));

    print_tokens(list);

    free_tokens(list);
    return 0;
}*/
