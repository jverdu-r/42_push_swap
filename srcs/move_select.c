/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_select.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:29:36 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/05/31 16:38:13 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

int	move_select(t_pile **listA, t_pile **listB, char *move, int moves)
{
	ft_printf("%s\n", move);
	if (ft_strcmp(move, "sa") == 0)
		lst_swap(*listA);
	if (ft_strcmp(move, "sb") == 0)
		lst_swap(*listB);
	if (ft_strcmp(move, "pa") == 0)
		lst_push(listA, listB);
	if (ft_strcmp(move, "pb") == 0)
		lst_push(listB, listA);
	if (ft_strcmp(move, "ra") == 0)
		lst_rotate(*listA);
	if (ft_strcmp(move, "rb") == 0)
		lst_rotate(*listB);
	if (ft_strcmp(move, "rra") == 0)
		lst_rev_rotate(*listA);
	if (ft_strcmp(move, "rrb") == 0)
		lst_rev_rotate(*listB);
	moves++;
	return (moves);
}

int	move_select_bis(t_pile **listA, t_pile **listB, char *move, int moves)
{
	ft_printf("used: %s\n", move);
	if (ft_strcmp(move, "ss") == 0)
	{
		lst_swap(*listA);
		lst_swap(*listB);
	}
	if (ft_strcmp(move, "rr") == 0)
	{
		lst_rotate(*listA);
		lst_rotate(*listB);
	}
	if (ft_strcmp(move, "rrr") == 0)
	{
		lst_rev_rotate(*listA);
		lst_rev_rotate(*listB);
	}
	lst_print(*listA, *listB);
	moves++;
	return (moves);
}
