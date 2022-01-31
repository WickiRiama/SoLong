# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mriant <mriant@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/20 11:37:43 by mriant            #+#    #+#              #
#    Updated: 2022/01/31 09:32:20 by mriant           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = so_long.c

OBJS = ${SRCS:.c=.o}

DEPS = ${SRCS:.c=.d}

CC = gcc

FLAGS = -Wall -Wextra -Werror -g3

KERNEL = $(shell uname -s)

ifeq ($(KERNEL), Linux)
	INC_DIR = $(addprefix -I, mlx_linux /usr/include)
	LIB_DIR = $(addprefix -L, mlx_linux /usr/lib)
	LIB_MLX = mlx_linux/libmlx.a
	FLAGS_OS = -lXext -lX11 -lm -lz
	RECIPE_OS = make -C mlx_linux
else
	INC_DIR = $(addprefix -I, mlx)
	LIB_DIR = $(addprefix -L, mlx)
	FLAGS_OS = -framework OpenGL -framework AppKit
	LIB_MLX = mlx/mlx.a
	RECIPE_OS = make -C mlx
endif

all: ${NAME}

${NAME}: ${LIB_MLX} ${OBJS}
	${CC} ${FLAGS} ${OBJS} ${LIB_DIR} -lmlx ${FLAGS_OS} -o ${NAME}

${LIB_MLX}:
	${RECIPE_OS}

%.o: %.c
	${CC} ${FLAGS} -MMD -c $< -o $@ ${INC_DIR}

clean:
	rm -rf ${OBJS} ${DEPS}

fclean: clean
	rm -rf ${NAME}
	${RECIPE_OS} clean

re: fclean all

-include ${DEPS}

.PHONY: clean fclean re
