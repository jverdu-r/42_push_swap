# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/30 19:03:06 by jverdu-r          #+#    #+#              #
#    Updated: 2022/04/05 19:07:20 by jverdu-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= lists.c push_swap_utils.c moves.c check_arg.c \
		  check_order.c push_swap.c

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
