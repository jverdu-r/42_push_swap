/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:39:05 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/04/04 19:39:58 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"



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
	ft_printf("listA creada\n");
	//lst_switch(&listA[0]);
	//listB = lst_swap(listA, listB);
	//listA = lst_del(listA); // swap debe de ir seguido de un del
	//listA = lst_rotate(listA);
	//listA = lst_rev_rotate(listA);
	//printf("check_dup: %d\n", check_dup(argc, argv));
	lst_print(listA, listB);
	lst_free(listA);
	lst_free(listB);
	system("leaks push_swap");
	return (0);
}
