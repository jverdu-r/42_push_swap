/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:09:56 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/04/20 19:49:13 by jverdu-r         ###   ########.fr       */
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

int	alg_5(t_pile **la, t_pile **lb, int moves)
{
	if (lst_length(*la) < 5)
	{
		moves = move_select(la, lb, "pb", moves);
		moves = alg_3(*la, *lb, moves);
		moves = re_join(la, lb, moves);
	}
	else
	{
		moves = move_select(la, lb, "pb", moves);
		moves = move_select(la, lb, "pb", moves);
		if (lb[0]->con < lb[0]->next->con)
			moves = move_select(la, lb, "sb", moves);
		moves = alg_3(*la, *lb, moves);
		moves = re_join(la, lb, moves);
	}
	return (moves);
}
