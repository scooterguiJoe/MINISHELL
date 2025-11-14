/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scootergui <scootergui@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 18:09:09 by scootergui        #+#    #+#             */
/*   Updated: 2025/11/14 18:02:46 by scootergui       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*t_token *lexer(char *input)
{
	int	i;
	t_token *tokens;

	tokens = NULL;
	i = 0;
	while(input[i])
	{
		if(ft_isspace)
	}

}*/
t_token	*ft_newtoken(t_token_type type, char *value)
{
	t_token *token;

	token = malloc(sizeof(t_token));
	token->type = type;
	token->value = value;
	token->next = NULL;
	return (token);
}

void	ft_addtoken(t_token **list, t_token *new)
{
	if(!*list)
		*list = new;
	else
	{
		t_token *tmp = *list;
		while(tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	free_tokens(t_token *list)
{
	t_token *tmp;
	while(list)
	{
		tmp = list->next;
		free(list->value);
		free(list);
		list = tmp;
	}
}

t_token	*ft_lexer(char *input)
{
	t_token			*list;
	int				i;
	char			*word;
	t_token_type	type;

	list = NULL;
	i = 0;
	while(input[i])
	{
		if(ft_isspace(input[i]))
			i++;
		else if(ft_isoperator(input[i]))
		{
			type = get_operator(input, &i);
			ft_addtoken(&list, ft_newtoken(type, strdup("")));
		}
		else
		{
			word = read_word(input, &i);
			ft_addtoken(&list, ft_newtoken(WORD, strdup("")));
		}
	}
	return(list);
}

