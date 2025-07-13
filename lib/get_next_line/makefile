# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itakumi <itakumi@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/14 17:15:58 by itakumi           #+#    #+#              #
#    Updated: 2025/07/13 20:48:35 by itakumi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra

NAME = get_next_line.a

SRCS = get_next_line_bonus.c get_next_line_utils_bonus.c

OBJS = $(SRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)


all: $(NAME)

re: fclean all

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

.PHONY: all re clean fclean
