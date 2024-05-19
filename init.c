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
    max_bits = count_bits(max);

    int i = 0;
    while (i < max_bits)
    {
        int j = 0;
        int size = lst_size(*stack_a);
        while (j < size)
        {
            if (((((*stack_a)->index) >> i)&1) == 0)
            {
                pb(stack_a, stack_b);
                ft_printf("pb\n");
            }
            else
            {
                rotate(stack_a);
                ft_printf("ra\n");
            }
            j++;
        }
        while (*stack_b)
        {
            pa(stack_a, stack_b);
            ft_printf("pa\n");
        }
        i++;
    }
}

typedef struct s_holder
{
    int a;
    int b;
    int c;
} t_holder;

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
    sort_three(stack_a);
    //something
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

    system("leaks -q push_swap");
}