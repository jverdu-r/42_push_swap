/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:52:06 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/04/19 19:05:39 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

int	check_order(p_list *list)
{
	int	i;

	i = 0;
	while (list->next)
	{
		if (list->next->con > list->con)
		{
			list = list->next;
			i++;
		}
		else
		{
			i++;
			return (i);
		}
	}
	i = 0;
	return (i);
}
