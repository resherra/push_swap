# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: recherra <recherra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/08 16:56:57 by recherra          #+#    #+#              #
#    Updated: 2024/05/08 16:56:58 by recherra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS=-Wall -Wextra -Werror
SRC=init.c
OBJ=$(SRC:.c=.o)
NAME=push_swap
FT_PRINTF=ft_printf/libftprintf.a

all: $(NAME)

$(NAME): $(FT_PRINTF) $(OBJ)
    cc $(CFLAGS) -o $(NAME) $(OBJ) $(FT_PRINTF)

$(FT_PRINTF):
    make -C ft_printf/

clean:
    make -C ft_printf/ clean
    rm -f $(OBJ)

fclean: clean
    make -C ft_printf/ fclean
    rm -f $(NAME)

re: fclean all
