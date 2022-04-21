/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:49:32 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/04/21 19:08:26 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

int	*check_dup(int	*ptr)
{
	int	i;
	int	j;

	i = 1;
	while (i < ptr[0])
	{
		printf("check_dup: %i\n", ptr[i]);
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

int	*check_num(char **ptr, int i)
{
	int	*pnum;
	int	j;
	int	a;

	j = 1;
	pnum = malloc(sizeof(int) * i);
	if (!pnum)
		return (NULL);
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
		pnum[j] = ft_atoi(ptr[j]);
		printf("pnum: %i\n", pnum[j]);
		j++;
	}
	pnum[0] = j;
	pnum = check_dup(pnum);
	return (pnum);
}
int	*splice_args(int count, char *args[])
{
	char	**ptr;
	int		*pnum;
	int		i;

	i = 0;
	if (count < 3)
		ptr = ft_split(args[1], ' ');
	else
		ptr = args;
	while (ptr[i])
		i++;
	pnum = check_num(ptr, i);
	return (pnum);
}

t_pile	*check_arg(int count, char *args[])
{
	int		*ptr;
	t_pile	*list;
	int		i;

	list = NULL;
	ptr = splice_args(count, args);
	if (!ptr)
		return (NULL);
	i = 1;
	while (i < ptr[0])
	{
		ft_printf("ptr[%i]: %i\n", i, ptr[i]);
		lst_add(&list, lst_new(ptr[i]));
		i++;
	}
	free(ptr);
	return (list);
}
