/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_U3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:31:39 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/04/06 16:39:34 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

int	alg_U3(p_list *listA, p_list *listB, int moves)
{
	if (listA->content > listA->next->content)
	{
		ft_printf("used 'sa'\n");
		lst_swap(listA);
		moves++;
		lst_print(listA, listB);
	}
	return (moves);
}
