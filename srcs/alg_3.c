/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:36:09 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/05/09 16:04:36 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

int	case1(t_pile *listA, t_pile *listB, int moves)
{
	moves = move_select(&listA, &listB, "sa", moves);
	return (moves);
}

int	case2(t_pile *listA, t_pile *listB, int moves)
{
	moves = move_select(&listA, &listB, "sa", moves);
	moves = move_select(&listA, &listB, "rra", moves);
	return (moves);
}

int	case3(t_pile *listA, t_pile *listB, int moves)
{
	moves = move_select(&listA, &listB, "ra", moves);
	return (moves);
}

int	case4(t_pile *listA, t_pile *listB, int moves)
{
	moves = move_select(&listA, &listB, "sa", moves);
	moves = move_select(&listA, &listB, "ra", moves);
	return (moves);
}

int	alg_3(t_pile *la, t_pile *lb, int moves)
{
	if (check_order(la) == 0)
		return (moves);
	if (la->con < la->next->next->con && \
			la->next->con < la->next->next->con)
		moves = case1(la, lb, moves);
	else if (la->con > la->next->con && \
			la->next->con > la->next->next->con)
		moves = case2(la, lb, moves);
	else if (la->con > la->next->next->con && \
			la->next->con < la->next->next->con)
		moves = case3(la, lb, moves);
	else if (la->next->con > la->next->next->con && \
			la->next->next->con > la->con)
		moves = case4(la, lb, moves);
	else if (la->con < la->next->con && \
				la->next->con > la->next->next->con)
			moves = move_select(&la, &lb, "rra", moves);
	return (moves);
}
