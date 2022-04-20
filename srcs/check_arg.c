/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:49:32 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/04/20 19:48:36 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

int	*check_dup(int	*ptr)
{
	int	i;
	int	j;

	i = 0;
	while (ptr[i])
	{
		j = i + 1;
		while (ptr[j])
		{
			if (ptr[i] == ptr[j])
				return (NULL);
			j++;
		}
		i++;
	}
	return (ptr);
}

void	free_aux(char *aux[])
{
	int	i;

	i = 0;
	while (aux[i])
		free(aux[i++]);
	free(aux);
}

char	**splice_args(int count, char *args[])
{
	char	**ptr;
	int		i;

	if (count < 3)
	{
		ptr = ft_split(args[1], ' ');
		i = 0;
	}
	else
	{
		ptr = args;
		i = 1;
	}
	return (ptr);
}

t_pile	*check_arg(int count, char *args[])
{
	char	**ptr;
	t_pile	*list;
	int		i;
	int		val;

	list = NULL;
	ptr = splice_args(count, args);
	if (!ptr)
		return (NULL);
	i = 1;
	while (ptr[i])
	{
		val = ft_atoi(ptr[i]);
		lst_add(&list, lst_new(val));
		i++;
	}
	return (list);
}
