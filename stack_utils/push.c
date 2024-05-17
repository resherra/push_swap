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
        t_stack *new_node = lstnew((*b)->value, -1);
        lstadd_front(a, new_node);
        free(*b);
        *b = (*b)->next;
    }
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
        t_stack *new_node = lstnew((*a)->value, -1);
        lstadd_front(b, new_node);
        free(*a);
        *a = (*a)->next;
    }
}