/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:52:19 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/04/19 19:39:58 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

p_list	*lst_new(int content)
{
	p_list	*new;

	new = malloc(sizeof(p_list));
	if (!new)
		return (NULL);
	new->con = content;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	lst_add(p_list **head, p_list *new)
{
	p_list	*aux;

	aux = *head;
	if (*head == NULL)
		*head = new;
	else
	{
		new->next = aux;
		aux->prev = new;
		aux = new;
		*head = aux;
	}
}

void	lst_del(p_list **list)
{
	if (list && *list)
	{
		if (lst_length(*list) > 1)
		{
			list[0] = list[0]->next;
			free(list[0]->prev);
			list[0]->prev = NULL;
		}
		else
		{
			free(list[0]);
			list[0] = NULL;
		}
	}
}

p_list	*lst_create(int *ptr, p_list *list)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		lst_add(&list, lst_new(ptr[i]));
		i++;
	}
	return (list);
}

void	lst_free(p_list *list)
{
	if (list)
	{
		while (list->next)
		{
			list = list->next;
			free(list->prev);
		}
		if (!list->next)
			free(list);
	}
}
