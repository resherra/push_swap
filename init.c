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


int countBits(unsigned int n)
{
    int count = 0;
    while (n)
    {
        count++;
        n >>= 1;
    }
    return count;
}

void radix(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *curr = *stack_a;
    unsigned int max = 0;
    int max_bits = 0;

    while (curr)
    {
        if (curr->index > max)
            max = curr->index;
        curr = curr->next;
    }
    max_bits = countBits(max);

    //check the bit -> push to b || rotate a (save the first rotate to a to break) -> push everything back a
    //increment to second bit.

    int save = -1;
    int i = 0;
    while (i < max_bits)
    {


        i++;
    }
//        while (1)
//        {
//            if (((((*stack_a)->index)>>i)&1) == 0)
//            {
//                pb(stack_a, stack_b);
//                printf("pb\n");
//            }
//            else if (((((*stack_a)->index)>>i)&1) == 1)
//            {
//                if (save == -1)
//                    save = (*stack_a)->index;
//                while (save != (*stack_a)->index)
//                {
//                    rotate(stack_a);
//                    printf("ra\n");
//                }
//                break;
//
//            }
//        }
//        while (1)
//        {
//            if (lst_size(*stack_b) == 0)
//                break;
//            pa(stack_a, stack_b);
//            printf("pa\n");
//        }
//        save = -1;
//        i++;
//    }
}



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
    radix(&stack_a, &stack_b);

    t_stack *curr = stack_a;
    while (curr)
    {
        printf("stack a %4d | %3d\n", curr->value, curr->index);
        curr = curr->next;
    }

    t_stack *curr_b = stack_b;
    while (curr_b)
    {
        printf("stack a %4d | %3d\n", curr_b->value, curr_b ->index);
        curr_b = curr_b->next;
    }

//    system("leaks -q push_swap");
}