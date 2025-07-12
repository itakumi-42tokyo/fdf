# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/11 09:28:50 by tigarashi         #+#    #+#              #
#    Updated: 2025/07/12 22:58:17 by itakumi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC 		= cc
CFLAGS	= -Wall -Werror -Wextra -I includes

SRC_DIR		= src
DRAW_DIR	= draw
INIT_DIR	= init

SRC		= \
	$(DRAW_DIR)/bla.c \
	$(DRAW_DIR)/dda.c \
	$(DRAW_DIR)/wla.c \
	$(INIT_DIR)/init.c \
	main.c \

OBJ		=$(SRC:%.c=%.o)

MLX_DIR		= minilibx-linux
MLX_LIB		= $(MLX_DIR)/libmlx.a
MLX_INC		= -I $(MLX_DIR)

LIB_DIR	= lib
LIB	=\
		libft\
		get_next_line

LIBS_HEAD = $(foreach l, $(LIB), -I $(LIB_DIR)/$(l))
LIBS_HEAD = $(foreach l, $(LIB), $(LIB_DIR)/$(l)/$(l).a)


MLX_FLAGS_LINUX	= -L $(MLX_DIR) -lmlx -lXext -lX11
MLX_FLAGS_MACOS	= -L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

UNAME_S	:= $(shell uname -s)
ifeq ($(UNAME_S), Linux)
	MLX_FLAGS = $(MLX_FLAGS_LINUX)
else
	MLX_FLAGS = $(MLX_FLAGS_MACOS)
endif
