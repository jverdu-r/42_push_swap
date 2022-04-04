/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:17:12 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/04/04 19:20:19 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

void	lst_print(p_list *listA, p_list *listB)
{
	p_list	*auxA;
	p_list	*auxB;
	int		i;

	auxA = listA;
	auxB = listB;
	i = 0;
	ft_printf("  A	|     B\n");
	while (i < lst_length(listA))
	{
		if (auxA)
		{
			ft_printf("  %d", auxA->content);
			auxA = auxA->next;
		}
		if (auxB)
		{
			ft_printf("	|     %d\n", auxB->content);
			auxB = auxB->next;
		}
		else
		ft_printf("\n");
		i++;
	}
}
