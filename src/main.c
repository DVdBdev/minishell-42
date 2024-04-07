/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:34:56 by dvan-den          #+#    #+#             */
/*   Updated: 2024/04/07 15:07:02 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_data	*g_data;

void	free_all(void)
{
	free(g_data->input);
	free(g_data);
}

//TODO: no printf
//TODO: make exit function (ctrl-d)
//TODO: Can I free input when input is NULL lol
int	main(int argc, char *argv[], char *env[])
{
	g_data = malloc(sizeof(t_data));
	init(argc, argv, env);
	while(g_data->status)
	{
		g_data->input = readline("$> ");
		if (g_data->input == NULL)
		{
			free_all();
			printf("exit\n");
			exit(0);
		}
		add_history(g_data->input);
		//parsing_input();
	}
}
