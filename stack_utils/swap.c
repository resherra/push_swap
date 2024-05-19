/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:19:35 by recherra          #+#    #+#             */
/*   Updated: 2024/05/19 16:19:36 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../init.h"

void swap(t_stack **stack)
{
    int tmp;

    tmp = (*stack)->value;
    (*stack)->value = (*stack)->next->value;
    (*stack)->next->value = tmp;
}