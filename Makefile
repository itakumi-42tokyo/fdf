# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/11 09:28:50 by tigarashi         #+#    #+#              #
#    Updated: 2025/07/19 18:24:47 by itakumi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME ?= fdf

CC 		?= cc
CFLAGS	= -Wall -Werror -Wextra

LDFlAGS = -lm

INC = -I includes

SRC_DIR		?= src
DRAW_DIR	?= draw
INIT_DIR	?= init
KEY_DIR		?= key
PROJ_DIR	?= projection
READ_DIR	?= read
UTILS_DIR	?= utils

SRC		= \
	$(DRAW_DIR)/bla.c \
	$(DRAW_DIR)/dda.c \
	$(DRAW_DIR)/wla.c \
	$(INIT_DIR)/init_mlx.c \
	$(INIT_DIR)/init_control.c \
	$(READ_DIR)/read_map.c \
	$(KEY_DIR)/esc_x.c \
	$(PROJ_DIR)/isometric.c \
	$(PROJ_DIR)/perspective.c \
	$(PROJ_DIR)/rad_deg.c \
	$(UTILS_DIR)/errmsg_exit.c \
	$(UTILS_DIR)/free_2d.c \
	$(UTILS_DIR)/my_abs.c \
	$(UTILS_DIR)/swap.c \
	$(UTILS_DIR)/ut_atoi_with_error.c \
	$(UTILS_DIR)/ut_count_target.c \
	$(UTILS_DIR)/ut_count_words.c \
	$(UTILS_DIR)/ut_issign.c \
	$(UTILS_DIR)/ut_isspace.c \
	main.c \

OBJ_DIR	?= build
OBJ		=$(SRC:%.c=$(OBJ_DIR)/%.o)

MLX_DIR		= $(LIB_DIR)/minilibx-linux
MLX_LIB		= $(MLX_DIR)/libmlx.a
MLX_INC		= -I $(MLX_DIR)

LIB_DIR	= lib
LIB	=\
		libft \
		get_next_line

LIBS_HEAD	= $(foreach l, $(LIB), -I $(LIB_DIR)/$(l))
LIBS		= $(foreach l, $(LIB), $(LIB_DIR)/$(l)/$(l).a)


MLX_FLAGS_LINUX	= -L $(MLX_DIR) -lmlx -lXext -lX11
MLX_FLAGS_MACOS	= -L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

UNAME_S	:= $(shell uname -s)
ifeq ($(UNAME_S), Linux)
	MLX_FLAGS = $(MLX_FLAGS_LINUX)
else
	MLX_FLAGS = $(MLX_FLAGS_MACOS)
endif

all: $(NAME)

$(NAME): $(LIBS) $(MLX_LIB) $(OBJ)
	$(CC) $(CFLAGS) $(INC) $(MLX_FLAGS) $(LIBS_HEAD) $(LIBS) $(MLX_LIB) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -g $(LIBS) $(MLX_LIB) $(INC) $(MLX_INC) $(LIBS_HEAD) -c $< -o $@

$(MLX_LIB):
	@if [ -d $(MLX_DIR) ]; then \
		$(MAKE) -C $(MLX_DIR); \
	else \
		printf "\033[31mMiniLibX directory $(MLX_DIR) not found.\033[0m\n"; \
		printf "Do you want to clone it? [y/n] "; \
		read -r ans; \
		if [ "$$ans" = "y" ] || [ "$$ans" = "Y" ] || [ "$$ans" = "yes" ]; then \
			git clone https://github.com/42Paris/minilibx-linux.git "$(MLX_DIR)"; \
			$(MAKE) -C "$(MLX_DIR)"; \
		else \
			echo "Skipping MiniLibX clone, build may fail."; \
			exit 1; \
		fi; \
	fi

%.a:
	$(MAKE) all -C $(dir $*)

clean:
	rm -rf $(OBJ_DIR)
	$(foreach l, $(LIB), $(MAKE) -C $(LIB_DIR)/$(l) clean;)
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -rf $(NAME)
	$(foreach l, $(LIB), $(MAKE) -C $(LIB_DIR)/$(l) fclean;)

re: fclean all

bonus:

debug: CFLAGS=
debug: all

PHONY: all clean fclean re bonus debug
