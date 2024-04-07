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

typedef struct	s_qlist
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

typedef struct	s_data
{
	int		status;
	char	*input;
}	t_data;

extern t_data	*g_data;

// init.c
void	init(int argc, char *argv[], char **ev);

#endif