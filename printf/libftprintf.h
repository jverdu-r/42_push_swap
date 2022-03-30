/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 19:11:10 by jverdu-r          #+#    #+#             */
/*   Updated: 2022/03/03 17:51:33 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_pf_putchar(int n);
int	ft_pf_putstr(char *str);
int	ft_pf_putptr( unsigned long int ptr, int i);
int	ft_pf_putdec(long long int nb, int i);
int	ft_pf_puthexa(unsigned long int nb, char type, int i);
int	ft_printf(const char *str, ...);

#endif
