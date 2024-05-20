/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:12:25 by recherra          #+#    #+#             */
/*   Updated: 2024/05/15 16:12:26 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../init.h"

void rotate(t_stack **stack)
{
    if (!(*stack)->next)
        return ;
    t_stack  *new_node = lstnew((*stack)->value, (*stack)->index);
    t_stack *curr = *stack;
    *stack = (*stack)->next;
    free(curr);
    lstadd_back(stack, new_node);
    ft_printf("ra\n");
}