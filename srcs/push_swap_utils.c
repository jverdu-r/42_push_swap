/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 18:54:31 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/06/16 17:56:45 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

int	lst_length(t_pile *list)
{
	int		i;
	t_pile	*aux;

	if (!list)
		return (0);
	aux = list;
	i = 0;
	while (aux)
	{
		aux = aux->next;
		i++;
	}
	return (i);
}

void	lst_print(t_pile *listA, t_pile *listB)
{
	int	i;
	int	j;

	if (lst_length(listA) > lst_length(listB))
		i = lst_length(listA);
	else
		i = lst_length(listB);
	j = 0;
	ft_printf("  A	|	 B\n");
	while (j < i)
	{
		if (listA)
		{
			ft_printf(" %d", listA->con);
			listA = listA->next;
		}
		if (listB)
		{
			ft_printf("	|	%d\n", listB->con);
			listB = listB->next;
		}
		else
			ft_printf("	|\n");
		j++;
	}
}

void	lst_free(t_pile *list)
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

int	*aproximity(t_pile *list)
{
	int		j;
	int		idx;
	int		*res;
	t_pile	*lst;

	lst = list;
	idx = lst->con;
	res = malloc(sizeof(int) * 2);
	j = lst_length(list) / 2;
	while (lst)
	{
		if (idx > lst->con)
			idx = lst->con;
		lst = lst->next;
	}
	res[0] = j;
	res[1] = idx;
	return (res);
}
