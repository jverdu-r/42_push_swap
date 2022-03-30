/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 17:15:59 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/03/29 19:19:07 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

void	lst_add(p_list	**head, p_list *new)
{
	p_list	*aux;

	aux = *head;
	if (*head == NULL)
		*head = new;
	else
	{
		while (aux != NULL)
		{
			if (aux->next == NULL)
			{
				aux->next = new;
				aux->next->prev = aux;
				aux = new;
			}
			aux = aux->next;
		}
	}
}
