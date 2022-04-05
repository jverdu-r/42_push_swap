/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:33:25 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/04/05 19:28:16 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

p_list	*lst_push(p_list *listA, p_list *listB)
{
	int	val;

	if (listA)
	{
		val = listA->content;
		lst_add(&listB, lst_new(val));
	}
	return (listB);
}

void	lst_swap(p_list *list)
{
	int	content;

	if (list->next)
	{
		content = list->content;
		list->content = list->next->content;
		list->next->content = content;
	}
}

p_list	*lst_rotate(p_list *list)
{
	int	val;

	val = list->content;
	while (list->next)
	{
		list->content = list->next->content;
		list = list->next;
	}
	list->content = val;
	while (list->prev)
		list = list->prev;
	return (list);
}

p_list	*lst_rev_rotate(p_list *list)
{
	int	val;

	while (list->next)
		list = list->next;
	val = list->content;
	while (list->prev)
	{
		list->content = list->prev->content;
		list = list->prev;
	}
	list->content = val;
	return (list);
}
