# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/11 09:28:50 by tigarashi         #+#    #+#              #
#    Updated: 2025/07/26 20:43:54 by itakumi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

override NAME		= fdf

CC 					?= cc
override CFLAGS		= -Wall -Werror -Wextra

LD_FLAGS	 		= -lm

INC 				= -I includes

SRC_DIR				?= src

SRC					= \
	draw/bla.c \
	draw/dda.c \
	draw/wla.c \
	execute/exec.c \
	free/free_exit.c \
	init/init_mlx.c \
	init/init_control.c \
	read/atoi_base_with_check.c \
	read/calc_row.c \
	read/read_map.c \
	key/esc_x.c \
	projection/isometric.c \
	projection/offset.c \
	projection/perspective.c \
	projection/rad_deg.c \
	projection/scale.c \
	utils/errmsg_exit.c \
	utils/free_2d.c \
	utils/my_abs.c \
	utils/swap.c \
	utils/ut_atoi_with_check.c \
	utils/ut_count_target.c \
	utils/ut_count_words.c \
	utils/ut_issign.c \
	utils/ut_isspace.c \
	utils/ut_split.c \
	view/auto_fit_scale.c \
	view/affine_transform.c \
	main.c \

OBJ_DIR				?= build
OBJ					=$(SRC:%.c=$(OBJ_DIR)/%.o)

MLX_DIR				= $(LIB_DIR)/minilibx-linux
MLX_LIB				= $(MLX_DIR)/libmlx.a
MLX_INC				= -I $(MLX_DIR)

LIB_DIR				= lib
LIB					=\
		libft \
		get_next_line

LIBS_HEAD			= $(foreach l, $(LIB), -I $(LIB_DIR)/$(l))
LIBS				= $(foreach l, $(LIB), $(LIB_DIR)/$(l)/$(l).a)


MLX_FLAGS_LINUX		= -L $(MLX_DIR) -lmlx -lXext -lX11
MLX_FLAGS_MACOS		= -L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

UNAME_S				:= $(shell uname -s)
ifeq ($(UNAME_S), Linux)
	MLX_FLAGS 		= $(MLX_FLAGS_LINUX)
else
	MLX_FLAGS 		= $(MLX_FLAGS_MACOS)
endif

all: $(NAME)

$(NAME): $(LIBS) $(MLX_LIB) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LD_FLAGS) $(INC) $(MLX_FLAGS) $(MLX_INC) $(LIBS_HEAD) $(LIBS) $(MLX_LIB) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -g $(INC) $(MLX_INC) $(LIBS_HEAD) -c $< -o $@

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
