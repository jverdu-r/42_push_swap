/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lib.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:45:17 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/04/19 18:39:57 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_LIB_H
# define PUSH_SWAP_LIB_H

#include <stdio.h>
#include <stdlib.h>
#include "./sources/libft/libft.h"
#include "./sources/printf/libftprintf.h"

typedef struct z_list
{
	int				con;
	struct z_list	*next;
	struct z_list	*prev;
}p_list;

p_list	*lst_new(int content);
p_list	*lst_create(int *ptr, p_list *list);
p_list	*check_arg(int count, char *args[]);
void	lst_del(p_list **list);
void	lst_rotate(p_list *list);
void	lst_rev_rotate(p_list *list);
void	lst_push(p_list **list, p_list **listA);
void	lst_add(p_list **head, p_list *new);
void	lst_swap(p_list *list);
void	lst_print(p_list *listA, p_list *listB);
void	lst_free(p_list *list);
int	move_select(p_list **listA, p_list **listB, char *move, int moves);
int	move_select_bis(p_list **listA, p_list **listB, char *move, int moves);
int	lst_length(p_list *list);
int	check_order(p_list *list);
int	alg_U3(p_list *la, p_list *lb, int moves);
int	alg_3(p_list *la, p_list *lb, int moves);
int	alg_5(p_list **la, p_list **lb, int moves);

#endif
