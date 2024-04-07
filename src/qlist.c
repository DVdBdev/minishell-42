/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qlist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <dvan-den@student.s19.be >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 18:56:20 by dvan-den          #+#    #+#             */
/*   Updated: 2024/04/07 19:23:08 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/**
 * @brief Creates a new node for a linked list of strings.
 * 
 * This function allocates memory for a new node in a linked list
 * of strings (`t_qlist`). It copies the provided string (`str`) and
 * assigns the given type to the node. The newly created node is
 * initialized with a NULL next pointer.
 * 
 * @param data The string value to be stored in the node.
 * @param type An integer value representing the type of the node.
 * @return A pointer to the newly created node, or NULL if memory 
 * allocation fails.
 */
t_qlist	*create_qlist_node(char *str, int type)
{
	t_qlist	*qlist;

	qlist = malloc(sizeof(t_qlist));
	qlist->str = ft_strdup(str);
	qlist->type = type;
	qlist->next = NULL;
	return (qlist);
}

/**
 * @brief Returns a pointer to the last node in the linked list.
 * 
 * This function traverses the linked list starting from the provided
 * head (`head`) until it reaches the last node.
 * 
 * @param head A pointer to the head of the linked list.
 * @return A pointer to the last node in the linked list, or NULL if the
 * list is empty.
 */
t_qlist	*get_last_qlist_node(t_qlist *head)
{
	if (!head)
		return (NULL);
	while (head)
	{
		if (head->next == NULL)
			return (head);
		head = head->next;
	}
	return (head);
}

/**
 * @brief Adds a new node to the back of the linked list.
 * 
 * This function adds a new node (`new_node`) to the back of the
 * linked list whose head is pointed to by `head`. If the linked list
 * is empty, it sets the provided node as the head of the list. Otherwise,
 * it traverses the list to find the last node and appends the new node to
 * it.
 * 
 * @param head A pointer to a pointer to the head of the linked list.
 * @param new_node A pointer to the node to be added to the linked list.
 */
void	append_qlist_node(t_qlist **head, t_qlist *new_node)
{
	t_qlist	*last;

	if (!new_node || !head)
		return ;
	if (!*head)
	{
		*head = new_node;
		return ;
	}
	last = get_last_qlist_node(*head);
	last->next = new_node;
}

/**
 * @brief Frees memory allocated for the linked list and its nodes.
 * 
 * This function iterates through the linked list, freeing the memory
 * for each node's string and the node itself. Finally, it sets the head
 * pointer to NULL to indicate that the list is now empty.
 * 
 * @param head A pointer to a pointer to the head of the linked list.
 */
void	clear_qlist(t_qlist **head)
{
	t_qlist	*tmp;

	if (!head)
		return ;
	while (*head)
	{
		tmp = (*head)->next;
		free((*head)->str);
		free(*head);
		*head = tmp;
	}
}
