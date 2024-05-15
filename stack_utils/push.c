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
    //something
    (void)a;
    (void)b;
}

void pb(t_stack **a, t_stack **b)
{
    (void)a;
    t_stack *curr = NULL;

    if (!(*b))
    {
        printf("here!\n");
        *b = *a;
        *a = *a + 1;
        (*b)->next = NULL;
    }
    else
    {
        curr = *b;
        while (curr->next)
        {
            curr = curr->next;
        }
        curr->next = *a;
        *a = *a + 1;
    }

//    while (curr->next)
//    {
//        curr = curr->next;
//    }




}