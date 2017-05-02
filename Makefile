# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbejot <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/02 22:42:19 by rbejot            #+#    #+#              #
#    Updated: 2016/05/02 22:46:27 by rbejot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

LIBPATH = ./libft/
LIBMXPATH = ./minilibx/

LIBS = -L$(LIBMXPATH) -lmlx -framework OpenGL -framework AppKit -L$(LIBPATH) -lft

SRC = display.c glynn.c hook.c image.c julia.c kawai.c key_hook.c main.c mandelbrot.c usage.c

OBJ = $(SRC:.c=.o)

CC = gcc -Wall -Wextra -Werror -O2

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@make -C $(LIBPATH)
	@make -C $(LIBMXPATH)
	@$(CC) -c $(SRC)
	@$(CC) $(OBJ) $(LIBS) -o $(NAME)
	@echo compiling...

clean:
	@rm -rf $(OBJ)
	@echo deleting...

fclean:
	@rm -f $(NAME)
	@echo deleting...

re: fclean all
