/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scootergui <scootergui@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 21:41:34 by scootergui        #+#    #+#             */
/*   Updated: 2025/11/10 17:32:09 by scootergui       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
# include <readline/readline.h>
# include <readline/history.h>

t_token *lexer(char *input)
{
	int	i;
	t_token *tokens;

	tokens = NULL;
	i = 0;
	while(input[i])
	{
		if(ft_isspace)
	}

}

int main(void)
{
	char *line;

	while(1)
	{
		setup_signals();
		line = readline("minishell> ");
		if(!line)
		{
			printf("exit\n");
			break;
		}
		if(*line)
			add_history(line);
		printf("Input: %s\n", line);
		free(line);
	}
	return (0);
}
