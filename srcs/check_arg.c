/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 18:27:39 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/05/30 19:52:46 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

t_pile	*null_list(t_pile *list)
{
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
			else
				list2 = list2->next;
		}
		list = list->next;
	}
	if (list->con == list2->con && lst_length(list) > 1)
		return (null_list(list));
	while (list->prev)
		list = list->prev;
	return (list);
}

t_pile	*check_num(char **ptr, int j)
{
	int		pnum;
	int		a;
	t_pile	*list;

	list = NULL;
	while (ptr[j])
	{
		a = 0;
		while (ptr[j][a])
		{
			if (ptr[j][a] == '-' || ptr[j][a] == '+')
				a++;
			else if (ft_isdigit(ptr[j][a] - 48) == 1)
				return (NULL);
			a++;
		}
		if (ft_strlen(ptr[j]) > 11)
			return (null_list(list));
		pnum = ft_atoi(ptr[j]);
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
