/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:56:48 by recherra          #+#    #+#             */
/*   Updated: 2024/05/08 16:56:50 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

//read, write, malloc, free,
//exit


typedef struct s_stack
{
    int value;
    struct s_stack *next;
} t_stack;


void	lstclear(t_stack **lst);
void	lstadd_back(t_stack **lst, t_stack *new);
t_stack *lstnew(int number);