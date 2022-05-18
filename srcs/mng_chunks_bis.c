/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mng_chunks_bis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:49:11 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/05/18 19:51:43 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

int	push_ba(t_pile **la, t_pile **lb, int *mov_ord, int check)
{
	int	moves;

	if (mov_ord[1] == 1)
	{
		while (lb[0]->con != check)
		{
			mov_ord[0] = move_select(la, lb, "rb", mov_ord[0]);
		}
		mov_ord[0] = move_select(la, lb, "pa", mov_ord[0]);
	}
	else
	{
		while (lb[0]->con != check)
		{
			mov_ord[0] = move_select(la, lb, "rrb", mov_ord[0]);
		}
		mov_ord[0] = move_select(la, lb, "pa", mov_ord[0]);
	}
	moves = mov_ord[0];
	free(mov_ord);
	return (moves);
}

int	push_order_big(t_pile **la, t_pile **lb, int moves)
{
	int		*mid_min;
	int		*mov_ord;
	int		idx;
	t_pile	*srch;

	mid_min = aproximity_big(*lb);
	mov_ord = malloc(sizeof(int) * 2);
	mov_ord[0] = moves;
	mov_ord[1] = 0;
	idx = 0;
	srch = *lb;
	while (srch->con != mid_min[1])
	{
		idx++;
		srch = srch->next;
	}
	if (idx < mid_min[0])
	{
		mov_ord[1] = 1;
		moves = push_ba(la, lb, mov_ord, mid_min[1]);
	}
	else
		moves = push_ba(la, lb, mov_ord, mid_min[1]);
	free (mid_min);
	return (moves);
}
