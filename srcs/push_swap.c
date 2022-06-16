/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:39:05 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/06/16 19:22:02 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

int	algo_select(t_pile **listA, t_pile **listB, int moves)
{
	int	chunk;

	if (lst_length(*listA) < 3)
		moves = alg_u3(*listA, moves);
	else if (lst_length(*listA) == 3)
		moves = alg_3(*listA, *listB, moves);
	else if (lst_length(*listA) > 3 && lst_length(*listA) < 11)
		moves = alg_10(listA, listB, moves);
	else if (lst_length(*listA) > 10 && lst_length(*listA) < 101)
	{
		moves = alg_big(listA, listB, moves, 4);
	}
	else if (lst_length(*listA) > 100)
	{
		chunk = lst_length(*listA) / 38;
		moves = alg_big(listA, listB, moves, chunk);
	}
	return (moves);
}	

int	push_swap(t_pile **listA, t_pile **listB)
{
	int	moves;

	moves = 0;
	moves = algo_select(listA, listB, moves);
	return (moves);
}

void	leaks(void)
{
	system("leaks push_swap");
}

int	main(int argc, char *argv[])
{
	t_pile	*list_a;
	t_pile	*list_b;
	int		moves;

	if (!argv[1])
		return (0);
	list_a = NULL;
	list_b = NULL;
	moves = 0;
	list_a = check_arg(argc, argv);
	if (!list_a)
		ft_printf("Error\n");
	else
	{
		if (check_order(list_a) != 0)
			moves = push_swap(&list_a, &list_b);
	}
	lst_free(list_a);
	lst_free(list_b);
	return (0);
}
