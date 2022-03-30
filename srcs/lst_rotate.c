/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:59:20 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/03/30 16:05:55 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

p_list	*lst_rotate(p_list *list)
{
	void	*value;

	value = list->content;
	while (list->next)
	{
		list->content  = list->next->content;
		list = list->next;
	}
	list->content = value;
	while(list->prev)
		list = list->prev;
	return (list);
}
