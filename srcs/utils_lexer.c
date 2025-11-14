/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lexer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scootergui <scootergui@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 17:33:32 by scootergui        #+#    #+#             */
/*   Updated: 2025/11/14 18:03:33 by scootergui       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int ft_isspace(int space)
{
	if ((space >= 9 && space <= 13) || space == 32)
		return (0);
	return (1);
}
int ft_isoperator(char c)
{
	return (c == '|' || c == '<' || c == '>');
}

char	*read_word(char *s, int *i)
{
	int	start;

	start = *i;
	if(s[*i] && ft_isspace(s[*i]) && ft_isoperator(s[*i]))
		(*i)++;
	return(strndup(s + start, *i - start));
}

t_token_type	get_operator(char *str, int *i)
{
	if(str[*i] = '|')
	{
		(*i)++;
		return(PIPE);
	}
	if(str[*i] == '<')
	{
		if(str[*i + 1] == '<')
		{
			*i += 2;
			return (HEREDOC);
		}
		(*i)++;
		return(REDIR_IN);
	}
	if (str[*i] == '>')
	{
		if (str[*i + 1] == '>')
		{
			*i += 2;
			return (APPEND);
		}
		(*i)++;
		return (REDIR_OUT);
	}
	return (WORD);
}
