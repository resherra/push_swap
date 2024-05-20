# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: recherra <recherra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/08 16:56:57 by recherra          #+#    #+#              #
#    Updated: 2024/05/13 21:42:18 by recherra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS=-Wall -Wextra -Werror
SRC=init.c list_utils.c parsing_utils.c pre_sort_utils.c stack_utils/push.c stack_utils/rotate.c stack_utils/rev_rotate.c stack_utils/swap.c miscs.c sort_three.c sort_five.c
OBJ=$(SRC:.c=.o)
NAME=push_swap
LIBFT=libft/libft.a
FT_PRINTF=ft_printf/libftprintf.a

all: $(NAME)

$(NAME): $(LIBFT) $(FT_PRINTF) $(OBJ) init.h
	cc $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(FT_PRINTF)

$(LIBFT):
	make -C libft/

$(FT_PRINTF):
	make -C ft_printf/

clean:
	make -C libft/ clean
	make -C ft_printf/ clean
	rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	make -C ft_printf/ fclean
	rm -f $(NAME)

re: fclean all
