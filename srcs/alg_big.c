/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_big.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:37:11 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/05/12 20:08:29 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

int	*get_key_big(t_pile *lk)
{
	int	len;
	int	idx;
	int	*key;
	int	i;
	int	a;

	key = malloc(sizeof(int) * 8);
	len = lst_length(lk);
	i = 0;
	a = 0;
	idx = len / 8;
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
int	*la_lk_big(t_pile *la)
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
//	lst_print(lk, la);
	key = get_key_big(lk);
	lst_free(lk);
	return(key);
}

int	alg_big(t_pile **la, t_pile **lb,  int moves)
{
	int *keys;
//	int i;

//	i = 0;
	keys = la_lk_big(*la);
/*	while (i < 8)
	{
		ft_printf("key[%i]: %i\n", i, keys[i]);
		i++;
	}*/
	moves = get_chunks(la, lb, moves, keys);
	free(keys);
	return (moves);
}

