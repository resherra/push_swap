/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:12:08 by recherra          #+#    #+#             */
/*   Updated: 2024/05/15 16:12:09 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../init.h"

void pa(t_stack **a, t_stack **b)
{
    if (!(*b))
        return;
    if (!(*a))
    {
        *a = *b;
        *b = (*b)->next;
        (*a)->next = NULL;
    }
    else
    {
        t_stack *new_node = lstnew((*b)->value, (*b)->index);
        lstadd_front(a, new_node);
        t_stack *curr = *b;
        *b = (*b)->next;
        free(curr);
    }
    ft_printf("pa\n");
}

void pb(t_stack **a, t_stack **b)
{
    if (!(*a))
        return ;
    if (!(*b))
    {
        *b = *a;
        *a = (*a)->next;
        (*b)->next = NULL;
    }
    else
    {
        t_stack *new_node = lstnew((*a)->value, (*a)->index);
        lstadd_front(b, new_node);
        t_stack *curr = *a;
        *a = (*a)->next;
        free(curr);
    }
    ft_printf("pb\n");
}