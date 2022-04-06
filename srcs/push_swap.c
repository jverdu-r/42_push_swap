/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:39:05 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/04/06 19:50:14 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

int	algo_select(p_list *listA, p_list *listB, int moves)
{
	lst_print(listA, listB);
	if (lst_length(listA) < 3)
		moves = alg_U3(listA, listB, moves);
	if (lst_length(listA) == 3)
		moves = alg_3(listA, listB, moves);
	return (moves);
}	

int	push_swap(p_list *listA, p_list *listB)
{
	int	moves;

	moves = 0;
	return (moves);
}

int	main(int argc, char *argv[])
{
	p_list	*listA;
	p_list	*listB;

	if (!argv[1])
		return (0);
	listB = NULL;
	listA = check_arg(argc, argv);
	if (!listA)
	{
		ft_printf("hay numeros duplicados\n");
		return (0);
	}
	push_swap(listA, listB);
	lst_free(listA);
	lst_free(listB);
	system("leaks push_swap");
	return (0);
}
