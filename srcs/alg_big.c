/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_big.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:37:11 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/05/17 21:24:21 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

int	*get_key_big(t_pile *lk, int chunk)
{
	int	len;
	int	idx;
	int	*key;
	int	i;
	int	a;

	key = malloc(sizeof(int) * chunk);
	len = lst_length(lk);
	i = 0;
	a = 0;
	idx = len / chunk;
	while (lk->next)
	{
		if (i == idx)
		{
			key[a] = lk->con;
			a++;
			i = 0;
		}
		i++;
		lk = lk->next;
	}
	return (key);
}

t_pile	*copy_lst_big(t_pile *la)
{
	t_pile	*lst;
	t_pile	*res;

	lst = la;
	res = NULL;
	while (lst->next)
	{
		lst_add(&res, lst_new(lst->con));
		lst = lst->next;
	}
	lst_add(&res, lst_new(lst->con));
	return (res);
}
int	*la_lk_big(t_pile *la, int chunk)
{
	t_pile	*lk;
	int		aux;
	int		*key;

	lk = copy_lst_big(la);
	while(check_order(lk) != 0)
	{
		while(lk->next)
		{
			if (lk->con > lk->next->con)
			{
				aux = lk->con;
				lk->con = lk->next->con;
				lk->next->con = aux;
			}
			lk = lk->next;
		}
		while (lk->prev)
			lk = lk->prev;
	}
	lst_print(lk, la);
	key = get_key_big(lk, chunk);
	lst_free(lk);
	return(key);
}

int	alg_big(t_pile **la, t_pile **lb,  int moves, int chunk)
{
	int *keys;
	int i;

	i = 0;
	keys = la_lk_big(*la, chunk);
/*	while (i < 8)
	{
		ft_printf("key[%i]: %i\n", i, keys[i]);
		i++;
	}*/
	moves = get_chunks_big(la, lb, moves, keys, chunk);
	free(keys);
	return (moves);
}

