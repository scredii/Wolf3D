# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abourgeu <abourgeu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/24 11:37:19 by abourgeu          #+#    #+#              #
#    Updated: 2017/04/22 19:30:58 by abourgeu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

CFLAGS = -Wall -Wextra -Werror

SRC = 	srcs/main.c srcs/key_code.c srcs/ft_init.c srcs/ft_draw.c \
		srcs/ft_mouse.c\

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	make -C ./libft
	make -C ./minilibx
	@gcc $(CFLAGS) -o $(NAME) -framework OpenGL -framework AppKit \
	minilibx/libmlx.a -lft -L./libft -I./libft $(OBJ)
	@echo "Wolf3d compiled."

all: $(NAME)

clean:
	make -C ./libft clean
	make -C ./minilibx clean
	rm -rf $(OBJ)

fclean : clean
	make -C ./libft fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean make fclean re
