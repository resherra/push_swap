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
#include <signal.h>


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


void sanitize(char *str, t_stack **stack_a)
{
    int i = 0;
    t_stack  *node;
    char **res;

    res = ft_split(str, ' ');
    if (!res)
        exit(1);
    while (res[i])
    {
        check(res[i]);
        node = lstnew(ft_atoi(res[i]));

        lstadd_back(stack_a, node);
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
    {
        sanitize(av[i++], &stack_a);
    }
//    while (stack_a->next)
//    {
//        printf("%d\n", stack_a->value);
//        stack_a = stack_a->next;
//    }
}