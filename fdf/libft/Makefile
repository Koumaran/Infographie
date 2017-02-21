# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsivanes <jsivanes42@gmail.com>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/17 21:17:01 by jsivanes          #+#    #+#              #
#    Updated: 2016/09/21 14:05:49 by jsivanes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a

HEAD = -Iheader/
C_DIR = srcs
O_DIR = objdir

FLAGS = -Wall -Wextra -Werror

C_FILES = $(shell find $(C_DIR) -type f -print | grep "\.c")
C_DIRS = $(shell find $(C_DIR) -type d -print)

O_DIRS = $(C_DIRS:$(C_DIR)/%=$(O_DIR)/%)
O_FILES= $(C_FILES:$(C_DIR)/%.c=$(O_DIR)/%.o)

all: $(NAME)

$(NAME): $(O_FILES)
	@echo "\033[0;32m**************************************\033[0m"
	@echo "\033[0;32m* ._.     ._. .__  .____. .________. *\033[0m"
	@echo "\033[0;32m* | |     | | |  \ | ___| |________| *\033[0m"
	@echo "\033[0;32m* | |     | | |__/ | |_.      | |    *\033[0m"
	@echo "\033[0;32m* | |___. | | |  \ | __|      | |    *\033[0m"
	@echo "\033[0;32m* |_____| |_| |__/ |_|        |_|    *\033[0m"
	@echo "\033[0;32m**************************************\033[0m"
	@echo "		BY SIVANESAN 2016 "
	@ar rc $@ $^
	@ranlib $@

$(O_DIR)/%.o: $(C_DIR)/%.c
	@mkdir -p $(O_DIRS) $(O_DIR)
	@gcc $(FLAGS) -o $@ -c $? $(HEAD)

.PHONY: clean fclean re

clean:
	@rm -rf $(O_DIR)

fclean: clean
	@rm $(NAME)
	
re: fclean all

