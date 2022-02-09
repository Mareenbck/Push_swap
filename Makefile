# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbascuna <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 08:26:22 by mbascuna          #+#    #+#              #
#    Updated: 2022/02/09 15:57:23 by mbascuna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
LIB_DIR		=	./libft
LIBFT		= ./libft/libft.a
HEADER		=	-I./push_swap.h
SRCS		= ./push_swap.c ./check.c ./move_a.c \
			./sort_a.c ./move_b.c ./sort_b.c \
			./call_a.c ./call_b.c ./utils.c \
			./main.c


OBJS	= ${SRCS:.c=.o}

RM		= rm -f

CC		= gcc

FLAGS	= -Wall -Wextra -Werror

all:		${NAME}


${NAME}:	${OBJS} ${LIBFT}
			@echo "\033[35m-----Compiling -----"
			@${CC} ${OBJS} -o ${NAME} ${LIBFT}
			@echo "\033[35m >>OK"
			
${LIBFT}:	
			@echo "\033[34m---Building Libft---"
			@make -sC libft
			@echo "\033[34m >>OK"

			
%.o:		%.c libft/*.c
			@${CC} ${CFLAGS} -c $< -o $@

clean:
			@echo "\033[32m---Cleaning Libft---"
			@make clean -sC ${LIB_DIR}
			@echo "\033[32m >>OK"
			@echo "\033[32m--Cleaning Objects--"
			${RM} ${OBJS}
			@echo "\033[32m >>OK"


fclean:		clean
			@echo "\033[32m----Cleaning All----"
			@make fclean -sC ${LIB_DIR}
			${RM} ${NAME}
			@echo "\033[32m >>OK"

re:			fclean all

.PHONY:		all clean fclean re
