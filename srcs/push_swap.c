/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:39:05 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/03/30 17:32:35 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

void	push_swap(int argc, char *argv[])
{
}

int	main(int argc, char *argv[])
{
	p_list	*listA;
	p_list	*listB;
	int		value;
	int		i;

	if (!argv[i])
		return (0);
	i = 1;
	listB = NULL;
	while (argv[i])
	{
		value = *argv[i] - '0';
		lst_add(&listA, lst_new(value));
		i++;
	}
	lst_switch(&listA[0]);
	listB = lst_swap(listA, listB);
	listA = lst_del(listA); // swap debe de ir seguido de un del
	listA = lst_rotate(listA);
	listA = lst_rev_rotate(listA);
	//printf("check_dup: %d\n", check_dup());
	lst_print(listA, listB, argc - 1);
	return (0);
}
