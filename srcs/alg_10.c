/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_10.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:26:23 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/05/19 17:52:54 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

int	re_join(t_pile **la, t_pile **lb, int moves)
{
	if (lb[0]->con > la[0]->next->next->con)
	{
		moves = move_select(la, lb, "pa", moves);
		moves = move_select(la, lb, "ra", moves);
	}
	while (lb[0])
	{
		if (la[0]->con > lb[0]->con)
			moves = move_select(la, lb, "pa", moves);
		else if (la[0]->con < lb[0]->con)
			moves = move_select(la, lb, "ra", moves);
	}
	while (check_order(*la) != 0)
			moves = move_select(la, lb, "ra", moves);
	return (moves);
}

int	push_ab(t_pile **la, t_pile **lb, int *mov_ord, int check)
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

int	push_order(t_pile **la, t_pile **lb, int moves)
{
	int		*mid_min;
	int		*mov_ord;
	int		idx;
	t_pile	*srch;

	mid_min = aproximity(*la);
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
		moves = push_ab(la, lb, mov_ord, mid_min[1]);
	}
	else
		moves = push_ab(la, lb, mov_ord, mid_min[1]);
	free (mid_min);
	return (moves);
}

int	alg_10(t_pile **la, t_pile **lb, int moves)
{
	while (lst_length(*la) != 3)
		moves = push_order(la, lb, moves);
	if (check_order(*la) > 0)
		moves = alg_3(*la, *lb, moves);
	moves = re_join(la, lb, moves);
	return (moves);
}
