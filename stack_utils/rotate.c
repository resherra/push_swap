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

void ra(t_stack **stack_a)
{
    if (!(*stack_a)->next)
        return ;
    t_stack *new_node = lstnew((*stack_a)->value, -1);
    free(*stack_a);
    *stack_a = (*stack_a)->next;
    lstadd_back(stack_a, new_node);
}

void rb(t_stack **stack_b)
{
    if (!(*stack_b)->next)
        return ;
    t_stack  *new_node = lstnew((*stack_b)->value, -1);
    free(*stack_b);
    *stack_b = (*stack_b)->next;
    lstadd_back(stack_b, new_node);
}

void rr(t_stack **stack_a, t_stack **stack_b)
{
    ra(stack_a);
    rb(stack_b);
}