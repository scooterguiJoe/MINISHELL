/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scootergui <scootergui@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 21:33:55 by scootergui        #+#    #+#             */
/*   Updated: 2025/11/14 18:03:28 by scootergui       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_SHELL_H
# define MINI_SHELL_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef enum e_token_type {
	WORD,
	PIPE,
	REDIR_IN,
	REDIR_OUT,
	REDIR_APPEND,
	HEREDOC,
	APPEND
} t_token_type;

typedef struct s_token {
	char *value;
	t_token_type type;
	struct s_token *next;
} t_token;

//parsing.c
void print_tokens(t_token *list);

//lexer.c
t_token	*ft_newtoken(t_token_type type, char *value);
void	ft_addtoken(t_token **list, t_token *new);
void	free_tokens(t_token *list);
t_token	*ft_lexer(char *input); //testar

//signs.c
void	setup_signals(void);

//utils_lexer.c
int ft_isspace(int space);
int				ft_isoperator(char c);
t_token_type	get_operator(char *str, int i);
char			*read_word(char *s, int *i); //Testar

#endif
