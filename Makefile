# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mriant <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/20 11:37:43 by mriant            #+#    #+#              #
#    Updated: 2022/01/20 13:33:34 by mriant           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = so_long.c

OBJS = ${SRCS:.c=.o}

DEPS = ${SRCS:.c=.d}

CC = gcc

FLAGS = -Wall -Wextra -Werror

INC_DIR = mlx

LIB_DIR = mlx

all: ${NAME}

${NAME}: ${LIB_DIR}/libmlx.a ${OBJS}
	${CC} ${FLAGS} $^ -L${LIB_DIR} -lmlx -framework OpenGL -framework AppKit -o ${NAME}

${LIB_DIR}/libmlx.a:
	make -C ${LIB_DIR}

%.o: %.c
	${CC} ${FLAGS} -MMD -c $< -o $@ -I${INC_DIR}

clean:
	rm -rf ${OBJS} ${DEPS}
	make -C ${LIB_DIR} clean

fclean: clean
	rm -rf ${NAME}
	make -C ${LIB_DIR} fclean

re: fclean all

-include ${DEPS}

.PHONY: clean fclean re

