/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 15:42:34 by recherra          #+#    #+#             */
/*   Updated: 2024/05/18 15:42:36 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"


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


void check(char *str, int *flag)
{
    int i;

    i = 0;
    while (str[i])
    {
        if ((str[i] == '-' || str[i] == '+'))
        {
            if (str[i] == '-')
                (*flag)++;
            if (str[i+1] < '0' || str[i+1] > '9')
            {
                ft_printf("Error\n");
                exit(1);
            }
        }
        else if (str[i] < '0' || str[i] > '9')
        {
            ft_printf("Error\n");
            exit(1);
        }
        i++;
    }
    (*flag)++;
}

void is_repeated(t_stack **stack_a, int value)
{
    t_stack *curr = (*stack_a);
    while (curr->next)
    {
        if (curr->value == value)
        {
            ft_printf("Error\n");
            exit(1);
        }
        curr = curr->next;
    }
}

void sanitize(char *str, t_stack **stack_a)
{
    int i;
    char **res;
    static int j;


    i = 0;
    res = ft_split(str, ' ');
    if (res == NULL)
        exit(1);
    while (res[i])
    {
        int flag = 0;
        check(res[i], &flag);
        int num = ft_atoi(res[i]);

        //check overflow
        if (num > 0 && flag == 2)
        {
            ft_printf("Error\n");
            exit(1);
        }
        if (num < 0 && flag == 1)
        {
            ft_printf("Error\n");
            exit(1);
        }

        //create a node && add it to back
        t_stack *new = lstnew(num, j);
        lstadd_back(stack_a, new);
        j++;

        //check if the value is already in the list;
        is_repeated(stack_a, num);
        free(res[i]);
        i++;
    }
    free(res);
}