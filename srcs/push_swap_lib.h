/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lib.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:45:17 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/04/21 17:18:32 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_LIB_H
# define PUSH_SWAP_LIB_H

# include <stdio.h>
# include <stdlib.h>
# include "./sources/libft/libft.h"
# include "./sources/printf/libftprintf.h"

typedef struct z_list
{
	int				con;
	struct z_list	*next;
	struct z_list	*prev;
}t_pile;

t_pile	*lst_new(int content);
t_pile	*lst_create(int *ptr, t_pile *list);
t_pile	*check_arg(int count, char *args[]);
void	lst_del(t_pile **list);
void	lst_rotate(t_pile *list);
void	lst_rev_rotate(t_pile *list);
void	lst_push(t_pile **list, t_pile **listA);
void	lst_add(t_pile **head, t_pile *new);
void	lst_add_back(t_pile **head, t_pile *new);
void	lst_swap(t_pile *list);
void	lst_print(t_pile *listA, t_pile *listB);
void	lst_free(t_pile *list);
int		move_select(t_pile **listA, t_pile **listB, char *move, int moves);
int		move_select_bis(t_pile **listA, t_pile **listB, char *move, int moves);
int		lst_length(t_pile *list);
int		check_order(t_pile *list);
int		alg_u3(t_pile *la, t_pile *lb, int moves);
int		alg_3(t_pile *la, t_pile *lb, int moves);
int		alg_5(t_pile **la, t_pile **lb, int moves);

#endif
