/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:12:16 by recherra          #+#    #+#             */
/*   Updated: 2024/05/15 16:12:17 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../init.h"

void rra(t_stack **stack_a)
{
    if (!(*stack_a)->next)
        return ;
    t_stack *prev = NULL;
    t_stack *curr = *stack_a;
    while (curr->next)
    {
        prev = curr;
        curr = curr->next;
    }
    t_stack *new_node = lstnew(curr->value);
    lstadd_front(stack_a, new_node);
    if (prev)
        prev->next = NULL;
    free(curr);
}

void rrb(t_stack **stack_b)
{
    if (!(*stack_b)->next)
        return ;
    t_stack *prev = NULL;
    t_stack *curr = *stack_b;
    while (curr->next)
    {
        prev = curr;
        curr = curr->next;
    }
    t_stack *new_node = lstnew(curr->value);
    lstadd_front(stack_b, new_node);
    if (prev)
        prev->next = NULL;
    free(curr);
}

void rrr(t_stack **stack_a, t_stack **stack_b)
{
    rra(stack_a);
    rrb(stack_b);
}