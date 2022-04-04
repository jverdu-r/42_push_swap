/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:58:28 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/04/04 16:06:40 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

void	lst_free(p_list *list)
{
	if (list)
	{
		while (list->next)
		{
			list = list->next;
			free(list->prev);
		}
			if (!list->next)
				free(list);
	}
}
