/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:34:35 by recherra          #+#    #+#             */
/*   Updated: 2024/05/20 16:49:29 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void	sort_three(t_stack **stack_a)
{
	t_holder	holder;

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
