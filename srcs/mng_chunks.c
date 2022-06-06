/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mng_chunks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:12:50 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/06/01 20:04:54 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

int	*aproximity_big(t_pile *list)
{
	int		j;
	int		idx;
	int		*res;
	t_pile	*lst;

	lst = list;
	idx = lst->con;
	res = malloc(sizeof(int) * 2);
	j = lst_length(list) / 2;
	while (lst)
	{
		if (idx < lst->con)
			idx = lst->con;
		lst = lst->next;
	}
	res[0] = j;
	res[1] = idx;
	return (res);
}

int	push_abc(t_pile **la, t_pile **lb, int *mov_ord, int check)
{
	int	moves;

	if (mov_ord[1] == 1)
	{
		while (la[0]->con != check)
		{
			mov_ord[0] = move_select(la, lb, "ra", mov_ord[0]);
		}
		mov_ord[0] = move_select(la, lb, "pb", mov_ord[0]);
	}
	else
	{
		while (la[0]->con != check)
		{
			mov_ord[0] = move_select(la, lb, "rra", mov_ord[0]);
		}
		mov_ord[0] = move_select(la, lb, "pb", mov_ord[0]);
	}
	moves = mov_ord[0];
	free(mov_ord);
	return (moves);
}

int	*aproximity_chunk(t_pile *list, int key)
{
	int		pos;
	int		*res;
	t_pile	*lst;

	lst = list;
	pos = 0;
	res = malloc(sizeof(int) * 2);
	res[0] = lst_length(list) / 2;
	while (lst)
	{
		if (lst->con <= key)
		{
			res[1] = lst->con;
			if (pos < res[0])
				return (res);
		}
		pos++;
		lst = lst->next;
	}
	return (res);
}

int	push_chunks(t_pile **la, t_pile **lb, int moves, int key)
{
	int		*mid_min;
	int		*mov_ord;
	int		idx;
	t_pile	*srch;

	mid_min = aproximity_chunk(*la, key);
	mov_ord = malloc(sizeof(int) * 2);
	mov_ord[0] = moves;
	mov_ord[1] = 0;
	idx = 0;
	srch = *la;
	while (srch->con != mid_min[1])
	{
		idx++;
		srch = srch->next;
	}
	if (idx < mid_min[0])
	{
		mov_ord[1] = 1;
		moves = push_abc(la, lb, mov_ord, mid_min[1]);
	}
	else
		moves = push_abc(la, lb, mov_ord, mid_min[1]);
	free(mid_min);
	return (moves);
}

int	get_chunks_big(t_pile **la, t_pile **lb, int *mov_chunk, int *keys)
{
	int	len;
	int	i;
	int	a;
	int	key;

	i = 0;
	a = 0;
	len = lst_length(*la);
	key = len / mov_chunk[1];
	while (lst_length(*la) >= (len / mov_chunk[1]))
	{
		mov_chunk[0] = push_chunks(la, lb, mov_chunk[0], keys[a]);
		if (i == key)
		{
			a++;
			key += len / mov_chunk[1];
		}
		i++;
	}
	while (lst_length(*la) > 0)
		mov_chunk[0] = push_order(la, lb, mov_chunk[0]);
	while (lb[0])
		mov_chunk[0] = push_order_big(la, lb, mov_chunk[0]);
	return (mov_chunk[0]);
}
