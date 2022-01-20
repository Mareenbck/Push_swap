# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbascuna <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 08:26:22 by mbascuna          #+#    #+#              #
#    Updated: 2022/01/20 11:14:21 by mbascuna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
LIB_DIR		=	libft
HEADER		=	-I./push_swap.h
SRCS	= ./push_swap.c ./check.c ./moove.c 


OBJS	= ${SRCS:.c=.o}

RM		= rm -f

CC		= gcc

FLAGS	= -Wall -Wextra -Werror

all:		${NAME}

%.o:%.c
			${CC} ${FLAGS} -c $< -o $@

${NAME}:	${OBJS} ./push_swap.h
			@echo "\033[35m----Compiling libft----"
			@make -C ${LIB_DIR}
			@${CC} ${FLAGS} ${HEADER} ${LIB_DIR}/libft.a ${OBJS} -o ${NAME} -fsanitize=address -g3

%.o:		%.c libft/*.c
			@${CC} ${CFLAGS} -c $< -o $@

clean:
			@make clean -C ${LIB_DIR}
			${RM} ${OBJS}


fclean:		clean
			@make fclean -C ${LIB_DIR}
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
