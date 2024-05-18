/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:21:08 by recherra          #+#    #+#             */
/*   Updated: 2024/05/08 17:21:10 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

int main(int ac, char **av)
{
    int i;
    t_stack *stack_a;
    t_stack *stack_b;

    stack_b = NULL;
    stack_a = NULL;
    i = 1;
    if (ac == 1)
        return 1;
    while(av[i])
        sanitize(av[i++], &stack_a);
    is_sorted(stack_a);
    index_stack(stack_a);


//    check values;
//    pb(&stack_a, &stack_b);
//    pb(&stack_a, &stack_b);
//    pb(&stack_a, &stack_b);
//    rr(&stack_a, &stack_b);
//    rrr(&stack_a, &stack_b);
//
    t_stack *curr = stack_a;
    while (curr)
    {
        printf("%3d | index %2d\n", curr->value, curr->index);
        curr = curr->next;
    }
//
//    t_stack *curr_b = stack_b;
//    while (curr_b)
//    {
//        printf("stack b -> %d\n", curr_b->value);
//        curr_b = curr_b->next;
//    }

    system("leaks -q push_swap");
}