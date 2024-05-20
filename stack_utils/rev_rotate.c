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

void rev_rotate(t_stack **stack)
{
    if (!(*stack)->next)
        return ;
    t_stack *prev = NULL;
    t_stack *curr = *stack;
    while (curr->next)
    {
        prev = curr;
        curr = curr->next;
    }
    t_stack *new_node = lstnew(curr->value, curr->index);
    lstadd_front(stack, new_node);
    if (prev)
        prev->next = NULL;
    free(curr);
    ft_printf("rra\n");
}