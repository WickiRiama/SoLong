# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mriant <mriant@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/20 11:37:43 by mriant            #+#    #+#              #
#    Updated: 2022/02/11 18:01:59 by mriant           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = $(addprefix ./srcs/, check_pos.c \
	cleaning.c \
	digits.c \
	get_next_line.c \
	get_next_line_utils.c \
	init_addr.c \
	init_img.c \
	init_pos.c \
	init_struct.c \
	keys.c \
	parsing.c \
	render.c \
	sl_utils.c \
	so_long.c)

OBJS = ${SRCS:.c=.o}

LIB_FT = libft/libft.a

DEPS = ${SRCS:.c=.d}

CC = clang

FLAGS = -Wall -Wextra -Werror -g3

KERNEL = $(shell uname -s)

ifeq ($(KERNEL), Linux)
	INC_DIR = $(addprefix -I, mlx_linux /usr/include includes libft)
	LIB_DIR = $(addprefix -L, mlx_linux /usr/lib libft)
	LIB_MLX = mlx_linux/libmlx.a
	FLAGS_OS = -lXext -lX11 -lm -lz
	RECIPE_OS = make -s -C mlx_linux
else
	INC_DIR = $(addprefix -I, mlx includes libft)
	LIB_DIR = $(addprefix -L, mlx libft)
	FLAGS_OS = -framework OpenGL -framework AppKit
	LIB_MLX = mlx/mlx.a
	RECIPE_OS = make -s -C mlx
endif

all: ${NAME}

${NAME}: ${LIB_MLX} ${LIB_FT} ${OBJS}
	${CC} ${FLAGS} ${OBJS} ${LIB_DIR} -lmlx -lft ${FLAGS_OS} -o ${NAME}

${LIB_MLX}:
	${RECIPE_OS}

${LIB_FT}:
	make -C libft bonus

%.o: %.c
	${CC} ${FLAGS} -MMD -c $< -o $@ ${INC_DIR}

clean:
	rm -rf ${OBJS} ${DEPS}
	make -C libft clean

fclean: clean
	rm -rf ${NAME}
	${RECIPE_OS} clean
	make -C libft fclean

re: fclean all

-include ${DEPS}

.PHONY: clean fclean re
