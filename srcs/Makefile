# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/30 19:03:06 by jverdu-r          #+#    #+#              #
#    Updated: 2022/04/04 19:45:22 by jverdu-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= lst_add.c lst_del.c lst_length.c lst_new.c lst_print.c \
		  lst_rev_rotate.c lst_rotate.c lst_swap.c lst_switch.c \
		  lst_free.c lst_create.c check_arg.c push_swap.c

OBJS	= ${SRCS:.c=.o}

NAME	= push_swap

PATH_LIBFT = sources/libft

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
		${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT} ${PRINTF}

all:	${NAME}

clean:
		${RM} ${OBJS}
		cd ${PATH_LIBFT} && ${MAKE} clean
		cd ${PATH_PRINTF} && ${MAKE} clean

fclean: clean
		${RM} ${NAME} ${PRINTF} ${LIBFT}
		

re:		fclean all

.PHONY: clean re all fclean
