/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_100.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:26:45 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/05/12 19:28:13 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

int	*get_key(t_pile *lk)
{
	int	len;
	int	idx;
	int	*key;
	int	i;
	int	a;

	key = malloc(sizeof(int) * 4);
	len = lst_length(lk);
	i = 0;
	a = 0;
	idx = len / 4;
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

t_pile	*copy_lst(t_pile *la)
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
int	*la_lk(t_pile *la)
{
	t_pile	*lk;
	int		aux;
	int		*key;

	lk = copy_lst(la);
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
	key = get_key(lk);
	lst_free(lk);
	return(key);
}

int	alg_100(t_pile **la, t_pile **lb,  int moves)
{
	int *keys;
	
	keys = la_lk(*la);
	moves = get_chunks(la, lb, moves, keys);
	free(keys);
	return (moves);
}
