/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_10.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:26:23 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/05/12 18:20:25 by jverdu-r         ###   ########.fr       */
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

int	push_ab(t_pile **la, t_pile **lb, int moves, int order, int check)
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
int	push_order(t_pile **la, t_pile **lb, int moves)
{
	int		*mid_min;
	int		idx;
	t_pile	*srch;

	mid_min = aproximity(*la);
	idx = 0;
	srch = *la;
	while (srch->con != mid_min[1])
	{
		idx++;
		srch = srch->next;
	}
	if (idx < mid_min[0])
		moves = push_ab(la, lb, moves, 1, mid_min[1]);
	else
		moves = push_ab(la, lb, moves, 0, mid_min[1]);
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
