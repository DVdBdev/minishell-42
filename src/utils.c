/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:47:53 by dvan-den          #+#    #+#             */
/*   Updated: 2024/04/08 16:48:41 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	is_space_char(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	return (0);
}

int	are_quote_chars(char c1, char c2)
{
	if ((c1 == '\'' || c1 == '\"') && c2 != '\\')
		return (1);
	return (0);
}

int	are_special_chars(char c1, char c2)
{
	if ((c1 == '|' || c1 == '<' || c1 == '>' || c1 == ';' || c1 == '&')
		&& c2 != '\\')
		return (1);
	return (0);
}

int	are_chars(char c1, char c2)
{
	if (c1 > ' ' && c < 127 && !are_special_chars(c1, c2)
		&& !are_quote_chars(c1, c2))
		return (0);
	return (1);
}
