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
}

void sanitize(char *str, t_stack **stack_a)
{
    int i;
    char **res;

    i = 0;
    res = ft_split(str, ' ');
    if (!res)
        exit(1);
    while (res[i])
    {
        check(res[i]);
        t_stack *new = lstnew(ft_atoi(res[i]));
        lstadd_back(stack_a, new);
        free(res[i]);
        i++;
    }
    free(res);
}

int main(int ac, char **av)
{
    int i;
    t_stack *stack_a;

    i = 1;
    if (ac == 1)
        return 1;
    while(av[i])
        sanitize(av[i++], &stack_a);
    t_stack *curr = stack_a;
    while (curr->next)
    {
        printf("%d\n", curr->value);
        curr = curr->next;
    }
    lstclear(&stack_a);
}