/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 18:27:39 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/06/16 19:21:38 by jverdu-r         ###   ########.fr       */
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
	int		pnum;
	int		a;
	t_pile	*list;

	list = NULL;
	while (pt[j])
	{
		a = 0;
		while (pt[j][a])
		{
			if (pt[j][a] == '-' || pt[j][a] == '+')
				a++;
			else if (ft_isdigit(pt[j][a] - 48) == 1)
				return (null_list(list));
			a++;
		}
		if ((ft_strlen(pt[j]) >= 10 && ft_atoi(pt[j]) == -1 && pt[j][0] != 0) \
			|| (ft_strlen(pt[j]) > 11))
			return (null_list(list));
		pnum = ft_atoi(pt[j]);
		lst_add_back(&list, lst_new(pnum));
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
	int		j;

	i = 0;
	j = 1;
	if (count < 3)
	{
		ptr = ft_split(args[1], ' ');
		j = 0;
		pnum = check_num(ptr, j);
		while (ptr[i])
		{
			free(ptr[i]);
			i++;
		}
		free(ptr);
	}
	else
	{
		ptr = args;
		pnum = check_num(ptr, j);
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
