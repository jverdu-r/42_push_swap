/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:52:19 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/06/16 17:55:11 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

t_pile	*lst_new(int content)
{
	t_pile	*new;

	new = malloc(sizeof(t_pile));
	if (!new)
		return (NULL);
	new->con = content;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	lst_add(t_pile **head, t_pile *new)
{
	t_pile	*aux;

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

void	lst_add_back(t_pile **head, t_pile *new)
{
	t_pile	*aux;

	aux = *head;
	if (*head == NULL)
		*head = new;
	else
	{
		while (aux)
		{
			if (!aux->next)
			{
				aux->next = new;
				new->prev = aux;
				aux = new;
			}
			aux = aux->next;
		}
	}
}

void	lst_del(t_pile **list)
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

t_pile	*lst_create(int *ptr, t_pile *list)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		lst_add_back(&list, lst_new(ptr[i]));
		i++;
	}
	return (list);
}
