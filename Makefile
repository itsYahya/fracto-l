# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/02 17:41:12 by yel-mrab          #+#    #+#              #
#    Updated: 2022/01/02 18:30:53 by yel-mrab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = control.c draw.c main.c utils.c
OBJ = ${SRC:.c=.o}
GCC = gcc -Wall -Wextra -Werror
NAME = fractol

all: $(NAME)

$(NAME): $(OBJ) 
	$(GCC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c fractol.h
	$(GCC) -c $< -o $@

bonus: all

clean:
	rm -rf $(OBJ)
	
fclean: clean
	rm -rf $(NAME)
	
re: fclean all