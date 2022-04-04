/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 19:22:25 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/04/04 18:19:17 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

p_list	*lst_create(int *ptr, p_list *list)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		ft_printf("%s\n", ptr[i]);
		lst_add(&list, lst_new(ptr[i]));
		i++;
	}
	return (list);
}
