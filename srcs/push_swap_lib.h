/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lib.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:45:17 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/03/30 19:32:14 by jverdu-r         ###   ########.fr       */
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
	void			*content;
	struct z_list	*next;
	struct z_list	*prev;
}p_list;

p_list	*lst_new(void *content);
p_list	*lst_swap(p_list *listA, p_list *listB);
p_list	*lst_del(p_list	*list);
p_list	*lst_rotate(p_list *list);
p_list	*lst_rev_rotate(p_list *list);
void	lst_add(p_list **head, p_list *new);
void	lst_switch(p_list *list);
void	lst_print(p_list *listA, p_list *listB, int count);
int	lst_length(p_list *list);
int	check_dup(int count, char **args);

#endif
