/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_rev_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:36:37 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/03/30 16:48:50 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

p_list	*lst_rev_rotate(p_list *list)
{
	void	*value;

	while (list->next)
		list = list->next;
	value = list->content;
	list->content = list->prev->content;
	while (list->prev)
	{
		list->content = list->prev->content;
		list = list->prev;
	}
	list->content = value;
	return (list);
}
