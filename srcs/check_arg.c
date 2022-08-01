/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 18:27:39 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/08/01 15:38:35 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

t_pile	*null_list(t_pile *list)
{
	if (list)
	{
		while (list->prev)
			list = list->prev;
	}
	lst_free(list);
	return (NULL);
}

t_pile	*check_dup(t_pile *list)
{
	t_pile	*list2;

	list2 = list;
	while (list->next)
	{
		if (list->next)
			list2 = list->next;
		while (list2->next)
		{
			if (list->con == list2->con)
				return (null_list(list));
			list2 = list2->next;
		}
		if (list->con == list2->con)
			return (null_list(list));
		list = list->next;
	}
	while (list->prev)
		list = list->prev;
	if (list->con == list2->con && lst_length(list) > 1)
		return (null_list(list));
	return (list);
}

t_pile	*check_num(char **pt, int j)
{
	int		a;
	t_pile	*list;

	list = NULL;
	while (pt[j])
	{
		a = 0;
		if (pt[j][a] == '-' || pt[j][a] == '+')
				a++;
		while (pt[j][a])
		{
			if (ft_isdigit(pt[j][a]) != 1 || \
					pt[j][a] == '-' || pt[j][a] == '+')
				return (null_list(list));
			a++;
		}
		if (ft_atoi(pt[j]) == -1 && check_long(pt, j) > 1)
			return (null_list(list));
		lst_add_back(&list, lst_new(ft_atoi(pt[j])));
		j++;
	}
	list = check_dup(list);
	return (list);
}

t_pile	*splice_args(int count, char **args)
{
	char	**ptr;
	t_pile	*pnum;
	int		i;

	i = 0;
	if (count < 3)
	{
		ptr = ft_split(args[1], ' ');
		pnum = check_num(ptr, 0);
		free_ptr(ptr);
	}
	else
	{
		ptr = splice(args, 1);
		pnum = check_num(ptr, 0);
		free_ptr(ptr);
	}
	return (pnum);
}

t_pile	*check_arg(int count, char *args[])
{
	t_pile	*list;

	list = NULL;
	list = splice_args(count, args);
	if (!list)
		return (NULL);
	return (list);
}
