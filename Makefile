# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbascuna <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 08:26:22 by mbascuna          #+#    #+#              #
#    Updated: 2022/01/26 09:54:05 by mbascuna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
LIB_DIR		=	./libft
LIBFT		= ./libft/libft.a
HEADER		=	-I./push_swap.h
SRCS	= ./push_swap.c ./check.c ./move_a.c ./sort_a.c ./move_b.c ./sort_b.c


OBJS	= ${SRCS:.c=.o}

RM		= rm -f

CC		= gcc

FLAGS	= -Wall -Wextra -Werror

all:		${NAME}

%.o:%.c
			${CC} ${FLAGS} -c $< -o $@

${NAME}:	${OBJS} ${LIBFT}
			@echo "\033[35m----Compiling libft----"
			@${CC} ${OBJS} -o ${NAME} ${LIBFT}
			
${LIBFT}:	
			@make -sC libft

			
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
