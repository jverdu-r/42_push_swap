/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:09:56 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/04/18 20:10:35 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

int re_join(p_list *la, p_list *lb, int moves)
{
	while (lb)
	{
		if (lb->con > la->con)
			moves += move_select(&la, &lb, "pa", moves);
		else 
			moves += move_select(&la, &lb, "sb", moves);
	}
	return (moves);
}

int	alg_5(p_list **la, p_list **lb, int moves)
{
/*	if (lst_length(la) < 5)
	{*/
		moves += move_select(la, lb, "pb", moves);
		moves += move_select(la, lb, "pa", moves);
	//	moves += alg_3(la, lb, moves);
	//	moves += re_join(la, lb, moves);
/*	}
	else
	{
		moves += move_select(&la, &lb, "pb", moves);
		moves += move_select(&la, &lb, "pb", moves);
		moves += alg_3(la, lb, moves);
		moves += re_join(la, lb, moves);
	}*/
	return (moves);
}
