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


int count_bits(unsigned int n)
{
    int count;

    count = 0;
    while (n)
    {
        count++;
        n = n >> 1;
    }
    return count;
}

void radix(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *curr;
    int size;
    unsigned int max;
    int max_bits;
    int i;
    int j;


    curr = *stack_a;
    max = 0;
    while (curr)
    {
        if (curr->index > max)
            max = curr->index;
        curr = curr->next;
    }
    max_bits = count_bits(max);
    i = 0;
    while (i < max_bits)
    {
        j = 0;
        size = lst_size(*stack_a);
        while (j < size)
        {
            if (((((*stack_a)->index) >> i)&1) == 0)
                pb(stack_a, stack_b);
            else
                rotate(stack_a);
            j++;
        }
        while (*stack_b)
            pa(stack_a, stack_b);
        i++;
    }
}

void init(t_holder *holder, t_stack *stack_a)
{
    holder->a = stack_a->value;
    holder->b = stack_a->next->value;
    holder->c = stack_a->next->next->value;
}

void sort_three(t_stack **stack_a)
{
    t_holder holder;

    init(&holder, *stack_a);
    if (holder.a > holder.b && holder.a > holder.c)
    {
        if (holder.b < holder.c)
            rotate(stack_a);
        else
        {
            swap(stack_a);
            rev_rotate(stack_a);
        }
    }
    else if (holder.a > holder.b && holder.b < holder.c)
        swap(stack_a);
    else if (holder.b > holder.a && holder.b > holder.c)
    {
        if (holder.a > holder.c)
            rev_rotate(stack_a);
        else
        {
            rev_rotate(stack_a);
            swap(stack_a);
        }
    }
}

void sort_five(t_stack **stack_a, t_stack **stack_b)
{
    int i;
    int min;
    int index;
    int size;
    int tmp;
    t_stack *curr;

    i = 0;
    while (i < 2)
    {
        curr = *stack_a;
        min = (*stack_a)->value;
        index = (*stack_a)->index;
        while (curr)
        {
            if (curr->value < min)
            {
                min = curr->value;
                index = curr->index;
            }
            curr = curr->next;
        }
        size = lst_size(*stack_a) - 1;
        tmp = size / 2;
        if (index < tmp)
        {
            while ((*stack_a)->value != min)
                rotate(stack_a);
        }
        else
        {
            while ((*stack_a)->value != min)
                rev_rotate(stack_a);
        }
        pb(stack_a, stack_b);
        i++;
    }
    sort_three(stack_a);
    while (*stack_b)
        pa(stack_a, stack_b);
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
    if (lst_size(stack_a) == 3)
        sort_three(&stack_a);
    else if (lst_size(stack_a) == 5)
        sort_five(&stack_a, &stack_b);
    else
    {
        index_stack(stack_a);
        radix(&stack_a, &stack_b);
    }
//
//
//    t_stack *curr = stack_a;
//    while (curr)
//    {
//        printf("%3d\n", curr->value);
//        curr = curr->next;
//    }

//    system("leaks -q push_swap");
}