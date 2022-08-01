/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:14:03 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/08/01 15:53:24 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

int	check_order(t_pile *list)
{
	int	i;

	i = 0;
	while (list->next != NULL)
	{
		if (list->next->con > list->con)
		{
			list = list->next;
			i++;
		}
		else
		{
			i++;
			return (i);
		}
	}
	i = 0;
	return (i);
}

int	check_long(char **pt, int idx)
{
	int	len;
	int	i;

	len = ft_strlen(pt[idx]);
	i = 0;
	if (pt[idx][0] == '+' || pt[idx][0] == '-')
		i++;
	while (pt[idx][i] == '0')
		i++;
	return (len - i);
}

int	splice_length(char **args, int i)
{
	int		j;
	int		len;

	len = 0;
	while (args[i])
	{
		j = 0;
		if (ft_strchr(args[i], ' '))
		{
			while (args[i][j])
			{
				if (args[i][j] == ' ')
				{
					len++;
				}
				len++;
				j++;
			}
		}
		else
			len++;
		i++;
	}
	return (len);
}

char	**splice(char **args, int i)
{
	char	**ptr;
	int		a;

	ptr = malloc(sizeof(char *) * splice_length(args, i) + 1);
	if (!ptr)
		return (NULL);
	a = 0;
	while (args[i])
	{
		if (ft_strchr(args[i], ' '))
			a = splice_bis(ptr, args, i, a);
		else
			ptr[a] = ft_strdup(args[i]);
		a++;
		i++;
	}
	ptr[a] = 0;
	return (ptr);
}

int	splice_bis(char **ptr, char **args, int i, int a)
{
	char	**aux;
	int		j;

	j = 0;
	aux = ft_split(args[i], ' ');
	while (aux[j])
		ptr[a++] = ft_strdup(aux[j++]);
	free_ptr(aux);
	a--;
	return (a);
}
