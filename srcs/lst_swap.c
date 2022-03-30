/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:22:02 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/03/30 15:48:54 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

p_list	*lst_swap(p_list *listA, p_list *listB)
{
	void	*value;
	if (listA)
	{
		value = listA->content;
		lst_add(&listB, lst_new(value));
	}
	return (listB);
}
