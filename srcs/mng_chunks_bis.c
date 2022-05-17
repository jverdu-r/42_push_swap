/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mng_chunks_bis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:49:11 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/05/17 21:02:31 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

int	push_ba(t_pile **la, t_pile **lb, int moves, int order, int check)
{
	if (order == 1)
	{
		while (lb[0]->con != check)
		{
			moves = move_select(la, lb, "rb", moves);
		}
		moves = move_select(la, lb, "pa", moves);
	}
	else
	{
		while (lb[0]->con != check)
		{
			moves = move_select(la, lb, "rrb", moves);
		}
		moves = move_select(la, lb, "pa", moves);
	}
	return (moves);
}

int	push_order_big(t_pile **la, t_pile **lb, int moves)
{
	int		*mid_min;
	int		idx;
	t_pile	*srch;

	mid_min = aproximity_big(*lb);
	idx = 0;
	srch = *lb;
	while (srch->con != mid_min[1])
	{
		idx++;
		srch = srch->next;
	}
	if (idx < mid_min[0])
		moves = push_ba(la, lb, moves, 1, mid_min[1]);
	else
		moves = push_ba(la, lb, moves, 0, mid_min[1]);
	free (mid_min);
	return (moves);
}
