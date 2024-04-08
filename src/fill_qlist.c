/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_qlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 19:38:30 by dvan-den          #+#    #+#             */
/*   Updated: 2024/04/08 17:06:27 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/**
 * @brief Parses characters enclosed in single or double quotes.
 * 
 * This function identifies characters enclosed in single or double
 * quotes in the input string and extracts them into a separate string.
 * It then creates a new node in the qlist linked list to store the
 * extracted string, along with a type identifier (1 for single quote,
 * 2 for double quote).
 * 
 * @param i Pointer to the current position in the input string.
 */
void	parse_quote_chars(int *i)
{
	int		j;
	int		space;
	char	*str;
	char	type;

	type = g_data->input[*i];
	(*i)++;
	j = *i;
	space = 0;
	j = count_quote_str(j, type);
	if (g_data->input[j + 1] == ' ')
		space = 1;
	str = malloc(sizeof(char) * (j - *i + 1));
	copy_quote_str(str, i, type, space);
	if (!is_space_char(g_data->input[(*i) - 1]) && g_data->input[(*i)])
		str = join_str(str, i);
	if (type == '\'')
		append_qlist_node(&g_data->qlist, create_qlist_node(str, 1));
	else if (type == '\"')
		append_qlist_node(&g_data->qlist, create_qlist_node(str, 2));
	free(str);
}

/**
 * @brief Parses special characters.
 * 
 * This function identifies consecutive special characters in the input
 * string and extracts them into a separate string. It then creates a
 * new node in the qlist linked list to store the extracted string,
 * along with a type identifier (3 for special characters).
 * 
 * @param i Pointer to the current position in the input string.
 */
void	parse_special_chars(int *i)
{
	int		j;
	int		space;
	char	*str;

	j = *i;
	space = 0;
	while (are_special_chars(g_data->input[j], g_data->input[j - 1]))
		j++;
	if (g_data->input[j] == ' ')
		space = 1;
	str = malloc(sizeof(char) * (j - *i + 1));
	j = 0;
	while (are_special_chars(g_data->input[*i], g_data->input[(*i) - 1]))
		str[j++] = g_data->input[((*i)++)];
	if (space)
		while (g_data->input[*i] == ' ')
			(*i)++;
	str[j] = '\0';
	append_qlist_node(&g_data->qlist, create_qlist_node(str, 3));
	free(str);
}

/**
 * @brief Parses regular characters.
 * 
 * This function identifies consecutive regular characters in the input
 * string and extracts them into a separate string. It then creates a
 * new node in the qlist linked list to store the extracted string, along
 * with a type identifier (0 for regular characters).
 * 
 * @param i Pointer to the current position in the input string.
 */
void	parse_chars(int *i)
{
	int		j;
	int		space;
	char	*str;

	j = (*i);
	space = 0;
	while (are_chars(g_data->input[j], g_data->input[j - 1]))
		j++;
	if (g_data->input[j] == ' ')
		space = 1;
	str = malloc(sizeof(char) * (j - *i + 1));
	j = 0;
	while (are_chars(g_data->input[*i], g_data->input[(*i) - 1]))
		str[j++] = g_data->input[((*i)++)];
	if (space)
		while (g_data->input[*i] == ' ')
			(*i)++;
	str[j] = '\0';
	append_qlist_node(&g_data->qlist, create_qlist_node(str, 0));
	free(str);
}

/**
 * @brief Fills the qlist linked list with parsed tokens from the
 * input string.
 * 
 * This function iterates through the input string and calls appropriate
 * parsing functions based on the type of characters encountered (regular,
 * special, or quoted). The parsed tokens are then added to the qlist
 * linked list for further processing.
 */
void	fill_qlist(void)
{
	int	i;

	i = 1;
	while (g_data->input[i])
	{
		if (are_chars(g_data->input[i], g_data->input[i - 1]))
			parse_chars(&i);
		else if (are_special_chars(g_data->input[i], g_data->input[i - 1]))
			parse_special_chars(&i);
		else if (are_quote_chars(g_data->input[i], g_data->input[i - 1]))
			parse_quote_chars(&i);
		if (g_data->input[i] == '\0')
			break ;
	}
}
