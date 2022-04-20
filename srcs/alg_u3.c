/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_U3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:31:39 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/04/20 17:20:09 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

int	alg_u3(t_pile *listA, t_pile *listB, int moves)
{
	if (listA->con > listA->next->con)
	{
		ft_printf("used 'sa'\n");
		lst_swap(listA);
		moves++;
		lst_print(listA, listB);
	}
	return (moves);
}
