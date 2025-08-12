# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/11 09:28:50 by tigarashi         #+#    #+#              #
#    Updated: 2025/08/12 08:30:45 by itakumi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

override NAME		= fdf

CC 					?= cc
override CFLAGS		= -Wall -Werror -Wextra

override PROJS		= iso persp
PROJ				= $(firstword $(PROJS))
PROJ_FLAG			= -D PROJ=0

ifeq ($(PROJ), persp)
	PROJ_FLAG		= -D PROJ=1
endif


LD_FLAGS	 		= -lm

INC 				= -I includes

SRC_DIR				?= src

SRC					= \
	draw/bla.c \
	draw/bla2.c \
	draw/dda.c \
	draw/wla.c \
	draw/render.c \
	draw/set_pixel.c \
	draw/trans_coord.c \
	execute/exec.c \
	exit/free_exit.c \
	init/alloc_proj.c \
	init/init_mlx.c \
	init/init_control.c \
	read/atoi_base_with_check.c \
	read/calc_row.c \
	read/read_map.c \
	pipeline/model/rotate/conversion.c \
	pipeline/model/rotate/euler_angles.c \
	pipeline/model/rotate/quaternion.c \
	pipeline/model/rotate/rotate_matrix.c \
	pipeline/model/rotate/slerp.c \
	pipeline/model/scale/scale.c \
	pipeline/model/translate/translate.c \
	interface/key/key.c \
	interface/mouse/mouse.c \
	interface/mouse/operate_win.c \
	pipeline/projection/isometric.c \
	pipeline/projection/perspective.c \
	pipeline/mvp.c \
	utils/rad_deg.c \
	utils/alloc_map.c \
	utils/check_extension.c \
	utils/copy_map.c \
	utils/errmsg_exit.c \
	utils/free_2d.c \
	utils/mul_mat4_vec4.c \
	utils/mul4x4_mat.c \
	utils/my_abs.c \
	utils/swap.c \
	utils/ut_atoi_with_check.c \
	utils/ut_count_target.c \
	utils/ut_count_words.c \
	utils/ut_issign.c \
	utils/ut_isspace.c \
	utils/ut_split.c \
	pipeline/view/auto_fit_scale.c \
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

$(NAME): $(PROJ_CHECK) $(LIBS) $(MLX_LIB) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LD_FLAGS) $(INC) $(MLX_FLAGS) $(MLX_INC) $(LIBS_HEAD) $(LIBS) $(MLX_LIB) $(PROJ_FLAG) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(PROJ_FLAG) -g $(INC) $(MLX_INC) $(LIBS_HEAD) -c $< -o $@

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

# $(MAKECMDGOALS):
# 	PROJ_FLAG = -D PROJ=0
# 	for i in ${!$(MAKECMDGOALS)[@]}
# 	do
# 		if [ $i = "persp" ]; then \
# 			PROJ_FLAG = -D PROJ=1; \
# 		fi
# 	done


#PROJ
define PROJ_CHECK
	ifeq ("$(filter $(PROJ), $(PROJS))", "")
		@echo "$(PROJ) is incorrect projection"
		@exit 1
	else
		@echo "PROJ: $(PROJ)"
	endif
endef

%.a:
	$(MAKE) all -C $(dir $*)

clean:
	rm -rf $(OBJ_DIR)
	$(foreach l, $(LIB), $(MAKE) -C $(LIB_DIR)/$(l) clean;)
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -rf $(NAME)
	$(foreach l, $(LIB), $(MAKE) -C $(LIB_DIR)/$(l) fclean;)

re:
	$(MAKE) fclean
	$(MAKE) all

bonus: all

debug: CFLAGS=
debug: all

persp:
	$(MAKE) debug PROJ=persp

iso:
	$(MAKE) debug PROJ=iso

.PHONY: all clean fclean re bonus debug persp iso
