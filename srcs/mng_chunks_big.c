/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mng_chunks_big.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:40:28 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/05/12 20:08:18 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

int	push_ab_big(t_pile **la, t_pile **lb, int moves, int order, int check)
{
	if (order == 1)
	{
		while (la[0]->con != check)
		{
			moves = move_select(la, lb, "ra", moves);
		}
		moves = move_select(la, lb, "pb", moves);
	}
	else
	{
		while (la[0]->con != check)
		{
			moves = move_select(la, lb, "rra", moves);
		}
		moves = move_select(la, lb, "pb", moves);
	}
	return (moves);
}

int	*aproximity_chunk_big(t_pile *list, int	key)
{
	int		i;
	int		pos;
	int		*res;
	t_pile	*lst;

	lst = list;
	i = 0;
	pos = -1;
	res = malloc(sizeof(int) * 2);
	res[0] = lst_length(list) / 2;
	while (lst)
	{
		if (lst->con <= key)
		{
			if ((i > res[0] && i > pos) || (i < res[0] && pos < i ))
			{
				res[1] = lst->con;
				pos = i;
			}
		}
		lst = lst->next;
		i++;
	}
	return (res);
}
int	push_chunks_big(t_pile **la, t_pile **lb, int moves, int key)
{
	int	*mid_min;
	int	idx;
	t_pile	*srch;

	mid_min = aproximity_chunk_big(*la, key);
	idx = 0;
	srch = *la;
	while (srch->con != mid_min[1])
	{
		idx++;
		srch = srch->next;
	}
	if (idx < mid_min[0])
		moves = push_ab_big(la, lb, moves, 1, mid_min[1]);
	else
		moves = push_ab_big(la, lb, moves, 0, mid_min[1]);
	free(mid_min);
	return (moves);
}

int	get_chunks_big(t_pile **la, t_pile **lb, int moves, int *keys)
{
	int	len;
	int	i;
	int	a;
	int	key;

	i = 0;
	a = 0;
	len = lst_length(*la);
	key = len / 8;
	while (lst_length(*la) > 63)
	{
		moves = push_chunks_big(la, lb, moves, keys[a]);
		if (i == key)
		{
			a++;
			key += key;
		}
		i++;
	}
	while (lst_length(*la) > 0)
		moves = push_order(la, lb, moves);
	while (lb[0])
		moves = push_order_big(la, lb, moves);
	return (moves);
}
