/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:49:32 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/04/18 16:20:29 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

int	*check_dup(int	*ptr)
{
	int i;
	int j;

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

int	*char_2_int(char *aux[], int i)
{
	int	j;
	int	trig;
	int	*ptr;

	j = 0;
	trig = i;
	while (aux[j])
		j++;
	ptr = malloc(sizeof(int) * j + 1);
	if (!ptr)
		return (NULL);
	j = 0;
	while (aux[i])
	{
		ptr[j] = ft_atoi(aux[i]);
		j++;
		i++;
	}
	ptr[j] = '\0';
	if (trig == 0)
		free_aux(aux);
	ptr = check_dup(ptr);
	return (ptr);
}

int	*splice_args(int count, char *args[])
{
	char	**aux;
	int		*ptr;
	int		i;

	if (count < 3)
	{
		aux = ft_split(args[1], ' ');
		i = 0;
	}
	else
	{
		aux = args;
		i = 1;
	}
	ptr = char_2_int(aux, i); 
	return (ptr);
}

p_list	*check_arg(int count, char *args[])
{
	int		*ptr;
	p_list	*list;
	int		i;

	list = NULL;
	ptr = splice_args(count, args);
	if (!ptr)
		return (NULL);
	i = 0;
	while (ptr[i])
	{
		lst_add(&list, lst_new(ptr[i]));
		i++;
	}
	free(ptr);
	return (list);
}
