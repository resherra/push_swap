/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:12:25 by recherra          #+#    #+#             */
/*   Updated: 2024/05/20 15:15:33 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../init.h"

void	rotate(t_stack **stack)
{
	t_stack	*new_node;
	t_stack	*curr;

	if (!(*stack)->next)
		return ;
	new_node = lstnew((*stack)->value, (*stack)->index);
	curr = *stack;
	*stack = (*stack)->next;
	free(curr);
	lstadd_back(stack, new_node);
	ft_printf("ra\n");
}
