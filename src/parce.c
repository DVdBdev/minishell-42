/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 16:33:54 by dvan-den          #+#    #+#             */
/*   Updated: 2024/04/07 16:49:14 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static char	*add_space_to_front(void)
{
	char	*tmp;
	char	*tmp2;

	tmp = g_data->input;
	tmp2 = ft_strjoin(" ", tmp);
	free(tmp);
	return (tmp2);
}

void	parse_input(void)
{
	g_data->input = ft_strtrim(g_data->input, " ");
	g_data->input = add_space_to_front();
}
