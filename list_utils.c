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

t_stack *lstnew(int number)
{
    t_stack *node;

    node = malloc(sizeof(t_stack));
    if (!node)
        return (NULL);
    node->value = number;
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

void	lstclear(t_stack **lst)
{
    t_stack 	*ne;

    if (!lst)
        return ;
    if (*lst)
    {
        while (*lst)
        {
            ne = *lst;
            *lst = (*lst)->next;
            free(ne);
        }
    }
}