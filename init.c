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
                ft_printf("Error 1\n");
                system("leaks -q push_swap");
                exit(1);
            }
        }
        else if (str[i] < '0' || str[i] > '9')
        {
            ft_printf("Error 2\n");
            system("leaks -q push_swap");
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
            ft_printf("Error 3\n");
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
    static int j;


    i = 0;
    res = ft_split(str, ' ');
    if (res == NULL)
    {
        system("leaks -q push_swap");
        exit(1);
    }
    while (res[i])
    {
        int flag = 0;
        check(res[i], &flag);
        int num = ft_atoi(res[i]);

        //check overflow
        if (num > 0 && flag == 2)
        {
            ft_printf("Error 4\n");
            exit(1);
        }
        if (num < 0 && flag == 1)
        {
            ft_printf("Error 5\n");
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
    printf("sorted\n");
    exit(1);
}

void sort_arr(int *arr, int len)
{
    int i = 0;
    int j = 0;

    while (i < len - 1)
    {
        j = 0;
        while (j < len - i - 1)
        {
            if (arr[j] > arr[j+1])
            {
                int tmp  = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
            j++;
        }
        i++;
    }

}

void act_index(t_stack *stack, int *arr, int len)
{
    t_stack *curr = stack;
    int i = 0;

    while (curr)
    {
        i = 0;
        while (i < len)
        {
            if (curr->value == arr[i])
            {
                curr->index = i;
            }
            i++;
        }
        curr = curr->next;
    }
}

void index_stack(t_stack *stack)
{
    int size;
    int *arr;
    t_stack *curr;

    curr = stack;
    size = lst_size(stack);
    arr = malloc(sizeof(int) * size);
    int i = 0;
    while (curr)
    {
        arr[i++] = curr->value;
        curr = curr->next;
    }

    sort_arr(arr, size);
    act_index(stack, arr, size);

    free(arr);
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