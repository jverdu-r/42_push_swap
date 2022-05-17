/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mng_chunks_big.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:40:28 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/05/17 21:24:04 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

int	get_chunks_big(t_pile **la, t_pile **lb, int moves, int *keys, int chunk )
{
	int	len;
	int	i;
	int	a;
	int	key;

	i = 0;
	a = 0;
	len = lst_length(*la);
	key = len / chunk;
	while (lst_length(*la) >= (len / chunk))
	{ 
		fprintf(stderr, "key: %i\n", keys[a]);
		moves = push_chunks(la, lb, moves, keys[a]);
		if (i == key)
		{
			a++;
			key += key;
		}
		i++;
	}
	while (lst_length(*la) > 0)
		moves = push_order(la, lb, moves);
	while (lb[0])
		moves = push_order_big(la, lb, moves);
	return (moves);
}
