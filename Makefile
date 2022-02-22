# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mriant <mriant@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/20 11:37:43 by mriant            #+#    #+#              #
#    Updated: 2022/02/22 11:30:34 by mriant           ###   ########.fr        #
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

DEPS = ${SRCS:.c=.d}

CC = cc

FLAGS = -Wall -Wextra -Werror -g

INC_DIR = $(addprefix -I, mlx_linux /usr/include includes libft)

LIB_DIR = $(addprefix -L, mlx_linux /usr/lib libft)

LIB_MLX = mlx_linux/libmlx.a

LIB_FT = libft/libft.a

LIBS = -lXext -lX11 -lm -lz -lmlx -lft

all: ${NAME}

${NAME}: ${LIB_MLX} ${LIB_FT} ${OBJS}
	${CC} ${FLAGS} ${OBJS} ${LIB_DIR} ${LIBS} -o ${NAME}

${LIB_MLX}:
	make -s -C mlx_linux

${LIB_FT}:
	make -s -C libft

%.o: %.c
	${CC} ${FLAGS} -MMD -c $< -o $@ ${INC_DIR}

bonus: ${NAME}

clean:
	rm -rf ${OBJS} ${DEPS}
	make -C libft clean

fclean: clean
	rm -rf ${NAME}
	make -s -C mlx_linux clean
	make -C libft fclean

re: fclean all

-include ${DEPS}

.PHONY: all clean fclean re bonus
