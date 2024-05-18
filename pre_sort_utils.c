/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 15:59:52 by recherra          #+#    #+#             */
/*   Updated: 2024/05/18 15:59:55 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"


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