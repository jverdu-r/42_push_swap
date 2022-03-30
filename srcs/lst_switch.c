/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_switch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:27:55 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/03/28 19:22:24 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

void	lst_switch(p_list *list)
{
	void *content;

	if (list->next != NULL)
	{
		content = list->content;
		list->content = list->next->content;
		list->next->content = content;
	}
}
