/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:39:05 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/04/08 15:46:01 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

int	algo_select(p_list **listA, p_list **listB, int moves)
{
	lst_print(*listA, *listB);
	if (lst_length(*listA) < 3)
		moves = alg_U3(*listA, *listB, moves);
	else if (lst_length(*listA) == 3)
		moves = alg_3(*listA, *listB, moves);
	else if (lst_length(*listA) > 3 && lst_length(*listA) < 6)
		moves = alg_5(*listA, *listB, moves);
	return (moves);
}	

int	push_swap(p_list **listA, p_list **listB)
{
	int	moves;

	moves = 0;
	moves = algo_select(listA, listB, moves);
	return (moves);
}

int	main(int argc, char *argv[])
{
	p_list	*listA;
	p_list	*listB;
	int		moves;

	if (!argv[1])
		return (0);
	moves = 0;
	listB = NULL;
	listA = check_arg(argc, argv);
	if (!listA)
	{
		ft_printf("hay numeros duplicados\n");
		return (0);
	}
	if (check_order(listA) != 0)
		moves = push_swap(&listA, &listB);
	else
		lst_print(listA, listB);
	//lst_push(listA, listB);
	//lst_del(&listA);
	//lst_print(listA, listB);
	lst_free(listA);
	lst_free(listB);
	ft_printf("numero de movimientos: %i\n", moves);
	//system("leaks push_swap");
	return (0);
}
