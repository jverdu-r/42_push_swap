/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:33:25 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/04/18 20:10:29 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

void	lst_push(p_list **listA, p_list **listB)
{
	p_list	*aux;
	int		val;

	val = listB[0]->con;
	aux = lst_new(val);
	aux->next = *listA;
	*listA = aux;
	if (lst_length(listB[0]) > 1)
		lst_del(listB);
	else
		listB[0] = NULL; 
}

void	lst_swap(p_list *list)
{
	int	content;

	if (list->next)
	{
		content = list->con;
		list->con = list->next->con;
		list->next->con = content;
	}
}

void	lst_rotate(p_list *list)
{
	int	val;

	val = list->con;
	while (list->next)
	{
		list->con = list->next->con;
		list = list->next;
	}
	list->con = val;
	while (list->prev)
		list = list->prev;
}

void	lst_rev_rotate(p_list *list)
{
	int	val;

	while (list->next)
		list = list->next;
	val = list->con;
	while (list->prev)
	{
		list->con = list->prev->con;
		list = list->prev;
	}
	list->con = val;
}

int	move_select(p_list **listA, p_list **listB, char *move, int moves)
{
	ft_printf("used : %s\n", move);
	if (ft_strcmp(move, "sa") == 0)
		lst_swap(*listA);
	if (ft_strcmp(move, "sb") == 0)
		lst_swap(*listB);
	if (ft_strcmp(move, "pa") == 0)
		lst_push(listA, listB);
	if (ft_strcmp(move, "pb") == 0)
		lst_push(listB, listA);
	if (ft_strcmp(move, "ra") == 0)
		lst_rotate(*listA);
	if (ft_strcmp(move, "rb") == 0)
		lst_rotate(*listB);
	if (ft_strcmp(move, "rra") == 0)
		lst_rev_rotate(*listA);
	if (ft_strcmp(move, "rrb") == 0)
		lst_rev_rotate(*listB);
	lst_print(*listA, *listB);
	moves++;
	return (moves);
}

int	move_select_bis(p_list **listA, p_list **listB, char *move, int moves)
{
	ft_printf("used : %s\n", move);
	if (ft_strcmp(move, "ss") == 0)
	{
		lst_swap(*listA);
		lst_swap(*listB);
	}
	if (ft_strcmp(move, "rr") == 0)
	{
		lst_rotate(*listA);
		lst_rotate(*listB);
	}
	if (ft_strcmp(move, "rrr") == 0)
	{
		lst_rev_rotate(*listA);
		lst_rev_rotate(*listB);
	}
	lst_print(*listA, *listB);
	moves += 2;
	return (moves);
}
