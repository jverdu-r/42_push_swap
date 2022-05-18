/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:33:25 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/05/12 19:22:04 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

void	lst_push(t_pile **listA, t_pile **listB)
{
	int		val;

	if (listB)
	{
		val = listB[0]->con;
		lst_add(listA, lst_new(val));
		lst_del(listB);
	}
}

void	lst_swap(t_pile *list)
{
	int	content;

	if (list->next)
	{
		content = list->con;
		list->con = list->next->con;
		list->next->con = content;
	}
}

void	lst_rotate(t_pile *list)
{
	int	val;

	val = list->con;
	while (list->next)
	{
		list->con = list->next->con;
		list = list->next;
	}
	list->con = val;
	while (list->prev)
		list = list->prev;
}

void	lst_rev_rotate(t_pile *list)
{
	int	val;

	while (list->next)
		list = list->next;
	val = list->con;
	while (list->prev)
	{
		list->con = list->prev->con;
		list = list->prev;
	}
	list->con = val;
}
