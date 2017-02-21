# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/04 20:34:30 by jsivanes          #+#    #+#              #
#    Updated: 2016/12/28 12:40:07 by jsivanes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

HEAD = fdf.h
C_DIR = ./
O_DIR = ./
PATH_INC = ./libft/header

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c \
	  parse_fdf.c \
	  bresenham.c \
	  error.c \
	  gestion_touch.c \
	  image_trade.c \
	  get_position.c

OBJ = $(patsubst %.c,%.o,$(addprefix $(C_DIR), $(SRC)))

all: $(NAME)

$(NAME): $(OBJ) $(HEAD)
	@make -C libft
	@$(CC) $(CFLAGS) -I $(PATH_INC) -c $(SRC)
	@$(CC) -o $(NAME) $(OBJ) -lm -L libft/ -lft -lmlx -framework OpenGL -framework AppKit

.PHONY: clean fclean

clean:
	@make -C libft/ clean
	@/bin/rm -f $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@/bin/rm -f $(NAME)

re: fclean all
