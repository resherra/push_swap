/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:11:41 by recherra          #+#    #+#             */
/*   Updated: 2024/05/14 17:11:43 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

t_stack *lstnew(int number, int index)
{
    t_stack *node;

    node = malloc(sizeof(t_stack));
    if (!node)
        return (NULL);
    node->value = number;
    node->index = index;
    node->next = NULL;

    return (node);
}

void	lstadd_back(t_stack **lst, t_stack *new)
{
    t_stack 	*curr;

    if (!lst)
        return ;
    if (!(*lst))
    {
        *lst = new;
        return ;
    }
    curr = *lst;
    while (curr->next)
        curr = curr->next;
    curr->next = new;
}

void	lstadd_front(t_stack **lst, t_stack *new)
{
    if (!lst)
        return ;
    if (*lst && new)
    {
        new->next = *lst;
        *lst = new;
    }
    else
        *lst = new;
}

int lst_size(t_stack *stack)
{
    int i;
    t_stack *curr;

    i = 0;
    curr = stack;
    while (curr)
    {
        i++;
        curr = curr->next;
    }
    return i;
}