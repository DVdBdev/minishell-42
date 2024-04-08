/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_qlist_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:50:27 by dvan-den          #+#    #+#             */
/*   Updated: 2024/04/08 17:31:37 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/**
 * @brief Counts the length of characters enclosed in quotes.
 * 
 * This function counts the number of characters enclosed in quotes
 * starting from the given index. It stops counting when the closing
 * quote is encountered, ignoring escaped quotes.
 * 
 * @param i The starting index in the input string.
 * @param type The type of quote character (' or ").
 * @return The count of characters enclosed in quotes.
 */
int	count_quote_str(int i, char type)
{
	while (g_data->input[i])
	{
		if (g_data->input[i] == type && g_data->input[i - 1] != '\\')
			break ;
		i++;
	}
	return (j);
}

/**
 * @brief Copies characters enclosed in quotes to a new string.
 * 
 * This function copies characters enclosed in quotes to a new string
 * starting from the given index. It stops copying when the closing
 * quote is encountered, ignoring escaped quotes.
 * 
 * @param str The destination string to copy the characters to.
 * @param i Pointer to the current position in the input string.
 * @param type The type of quote character (' or ").
 * @param space Flag indicating whether to skip spaces after the quoted
 * string.
 */
void	copy_quote_str(char *str, int *i, char type, int space)
{
	int	j;

	j = 0;
	while (g_data->input[*i])
	{
		if (g_data->input[*i] == type && g_data->input[*i - 1] != '\\')
			break ;
		str[j++] = g_data->input[((*i)++)];
	}
	if (space)
	{
		(*i)++;
		while (g_data->input[*i] == ' ')
			(*i)++;
	}
	else
		(*i)++;
	str[j] = '\0';
}

/**
 * @brief Joins consecutive regular characters to a string.
 * 
 * This function joins consecutive regular characters from the input
 * string into a new string. It continues joining characters until a
 * non-character or the end of string is encountered.
 * 
 * @param first_str The first string to be joined.
 * @param i Pointer to the current position in the input string.
 * @return The new string resulting from joining consecutive regular
 * characters.
 */
char	*char_join(char *first_str, int *i)
{
	int		j;
	int		space;
	char	*str;
	char	*new_str;

	j = *i;
	space = 0;
	while (are_chars(g_data->input[j], g_data->input[j - 1])
		&& g_data->input[j])
		j++;
	if (g_data->input[j] == ' ')
		space = 1;
	str = malloc(sizeof(char) * (j - *i + 1));
	j = 0;
	while (are_chars(g_data->input[*i], g_data->input[(*i) - 1])
		&& g_data->input[*i])
		str[j++] = g_data->input[((*i)++)];
	if (space)
		while (g_data->input[*i] == ' ')
			(*i)++;
	str[j] = '\0';
	new_str = ft_strjoin(first_str, str);
	free(str);
	return (new_str);
}

/**
 * @brief Joins characters enclosed in quotes to a string.
 * 
 * This function joins characters enclosed in quotes from the input
 * string into a new string. It continues joining characters until the
 * closing quote is encountered, ignoring escaped quotes.
 * 
 * @param first_str The first string to be joined.
 * @param index Pointer to the current position in the input string.
 * @return The new string resulting from joining characters enclosed in
 * quotes.
 */
char	*quote_join(char *first_str, int *i)
{
	int		j;
	int		space;
	char	*str;
	char	type;
	char	*new_str;

	type = g_data->input[*i];
	(*i)++;
	j = *i;
	space = 0;
	while (g_data->input[j] != type && g_data->input[j - 1] != '\\')
		j++;
	if (g_data->input[j + 1] == ' ')
		space = 1;
	str = malloc(sizeof(char) * (j - *i + 1));
	copy_quote_str(str, i, type, space);
	new_str = ft_strjoin(first_str, str);
	if (_quote(g_data->input[(*i) - 1], g_data->input[(*i) - 2])
		&& g_data->input[(*i)])
		new_str = quote_join(new_str, i);
	else if (_char(g_data->input[(*i) - 1], g_data->input[(*i) - 2])
		&& g_data->input[(*i)])
		new_str = char_join(new_str, i);
	free(str);
	return (new_str);
}

/**
 * @brief Joins characters or strings based on their type.
 * 
 * This function determines whether the next set of characters in the
 * input string are enclosed in quotes or are regular characters. It then
 * calls the appropriate joining function (quote_join or char_join) to
 * concatenate them to the existing string.
 * 
 * @param first_str The first string to be joined.
 * @param index Pointer to the current position in the input string.
 * @return The updated string resulting from joining characters or strings.
 */
char	*join_str(char *first_str, int *i)
{
	if (are_quote_chars(g_data->input[*i], g_data->input[*i - 1]))
		first_str = quote_join(first_str, i);
	else if (are_chars(g_data->input[*i], g_data->input[*i - 1]))
		first_str = char_join(first_str, i);
	return (first_str);
}
