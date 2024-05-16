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

void check(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if ((str[i] == '-' || str[i] == '+'))
        {
            if (str[i+1] < '0' || str[i+1] > '9')
            {
                ft_printf("Error\n");
                system("leaks -q push_swap");
                exit(1);
            }
        }
        else if (str[i] < '0' || str[i] > '9')
        {
            ft_printf("Error\n");
            system("leaks -q push_swap");
            exit(1);
        }
        i++;
    }
}

void is_repeated(t_stack **stack_a, int value)
{
    t_stack *curr = (*stack_a);
    while (curr->next)
    {
        if (curr->value == value)
        {
            ft_printf("Error / repeated\n");
            system("leaks -q push_swap");
            exit(1);
        }
        curr = curr->next;
    }
}

void sanitize(char *str, t_stack **stack_a)
{
    int i;
    char **res;

    i = 0;
    res = ft_split(str, ' ');
    if (res == NULL)
    {
        system("leaks -q push_swap");
        exit(1);
    }
    while (res[i])
    {
        check(res[i]);

        //create a node && add it to back
        t_stack *new = lstnew(ft_atoi(res[i]));
        lstadd_back(stack_a, new);

        //check if the value is already in the list;
        is_repeated(stack_a, ft_atoi(res[i]));
        free(res[i]);
        i++;
    }
    free(res);
}

void is_sorted(t_stack *stack_a)
{
    t_stack *curr = stack_a;

    while (curr)
    {
        t_stack *tes = curr;
        while (tes)
        {
            if (curr->value > tes->value)
                return;
            tes = tes->next;
        }
        curr = curr->next;
    }
    exit(1);
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

//    check values;
//    pb(&stack_a, &stack_b);
//    pb(&stack_a, &stack_b);
//    pb(&stack_a, &stack_b);
//    ra(&stack_a);
//    rb(&stack_b);
//    rrr(&stack_a, &stack_b);
//
//    t_stack *curr = stack_a;
//    while (curr)
//    {
//        printf("stack a -> %d\n", curr->value);
//        curr = curr->next;
//    }
//
//    t_stack *curr_b = stack_b;
//    while (curr_b)
//    {
//        printf("stack b -> %d\n", curr_b->value);
//        curr_b = curr_b->next;
//    }

    system("leaks -q push_swap");
}