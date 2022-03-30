# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/30 19:03:06 by jverdu-r          #+#    #+#              #
#    Updated: 2022/03/30 20:12:38 by jverdu-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SCRS	= lst_add.c lst_del.c lst_length.c lst_new.c lst_print.c \
		  lst_rev_rotate.c lst_rotate.c lst_swap.c lst_switch.c \
		  push_swap.c

OBJS	= ${SRCS:.c=.o}

NAME	= push_swap.a

PATH_LIBFT	= sources/libft

LIBFT	= sources/libft/libft.a

PATH_PRINTF	= sources/printf

PRINTF	= sources/printf/libftprintf.a

CC		= gcc

RM		= rm -f

CFLAGS  = -Wall -Werror -Wextra

.c.o:
		${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
		make -sC ${PATH_LIBFT}
		make -sC ${PATH_PRINTF}
		ar rc ${OBJS} ${NAME} ${LIBFT} ${PRINTF}

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re:		fclean all

.PHONY: clean re all fclean
