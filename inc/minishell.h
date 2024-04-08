/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:32:44 by dvan-den          #+#    #+#             */
/*   Updated: 2024/04/08 17:33:20 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <sys/wait.h>

typedef struct s_qlist
{
	char			*str;
	int				type;
	struct s_qlist	*next;
}	t_qlist;

// typedef struct	s_ms
// {
// 	char		**words;
// 	int			type;
// 	int			size;
// 	struct s_ms	*next;
// }	t_ms;

typedef struct s_data
{
	int		status;
	char	*input;
	t_qlist	*qlist;
}	t_data;

extern t_data	*g_data;

/*------------UTILS------------*/
int		is_space_char(char c);
int		are_quote_chars(char c1, char c2);
int		are_special_chars(char c1, char c2);
int		are_chars(char c1, char c2);
int		count_quote_str(int i, char type);
void	copy_quote_str(char *str, int *i, char type, int space);
char	*char_join(char *first_str, int *i);
char	*quote_join(char *first_str, int *i);
char	*join_str(char *first_str, int *i);

/*------------QLIST------------*/
t_qlist	*create_qlist_node(char *str, int type);
t_qlist	*get_last_qlist_node(t_qlist *head);
void	append_qlist_node(t_qlist **head, t_qlist *new_node);
void	clear_qlist(t_qlist **head);

// init.c
void	init(int argc, char *argv[], char **ev);

#endif