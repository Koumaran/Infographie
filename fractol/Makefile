# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsivanes <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/28 12:27:20 by jsivanes          #+#    #+#              #
#    Updated: 2016/12/31 19:32:19 by jsivanes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = main_fractol.c mandelbrot.c luncher.c events.c color.c julia.c

OBJ = $(SRC:.c=.o)

CC = gcc -Wall -Wextra -Werror

LIBS = -Llibft -Lminilibx_macos

$(NAME): $(OBJ)
	@echo "Welcome to the world of Fract'ol"
	@make -C libft
	@make -C minilibx_macos
	@$(CC) -o $@ $^ $(LIBS) -lft -lmlx -framework OpenGL -framework AppKit
	@echo "\033[32mFract'ol compiled\033[0m"

all: $(NAME)

%.o: %.c
	@$(CC) -o $@ -c $< -I. -I libft/header/

clean:
	@make clean -C libft
	@make -C minilibx_macos clean
	@rm -f $(OBJ)

fclean: clean
	@make -C libft fclean
	rm -f $(NAME)

re: fclean all
