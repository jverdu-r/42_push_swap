/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:36:09 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/04/06 19:27:15 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

int	case1(p_list *listA, p_list *listB, int moves)
{
	moves = move_select(listA, listB, "sa", moves);
	return (moves);
}

int	case2(p_list *listA, p_list *listB, int moves)
{
	moves = move_select(listA, listB, "sa", moves);
	moves = move_select(listA, listB, "rra", moves);
	return (moves);
}

int	case3(p_list *listA, p_list *listB, int moves)
{
	moves = move_select(listA, listB, "ra", moves);
	return (moves);
}

int	case4(p_list *listA, p_list *listB, int moves)
{
	moves = move_select(listA, listB, "sa", moves);
	moves = move_select(listA, listB, "ra", moves);
	return (moves);
}

int	alg_3(p_list *la, p_list *lb, int moves)
{
	if (la->con > la->next->con)
	{
		if (la->con < la->next->next->con && \
				la->next->con < la->next->next->con)
			moves = case1(listA, moves);
		if (la->con > la->next->next->con && \
				la->next->con > la->next->next->con)
			moves = case2(listA, listB, moves);
		if (la->con > la->next->next->con && \
				la->next->con < la->next->next->con)
			moves = case3(listA, listB, moves);
	}
	if (la->con < la->next->con)
	{
		if (la->next->con > la->next->next->con)
			moves = case4(listA, listB, moves);
		if (la->next->con < la->next->next->con)
			moves = move_select(listA, listB, "rra", int moves);
	}
	return (moves);
}
