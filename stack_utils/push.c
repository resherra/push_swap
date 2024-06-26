/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:12:08 by recherra          #+#    #+#             */
/*   Updated: 2024/05/20 15:15:57 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../init.h"

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*new_node;
	t_stack	*curr;

	if (!(*b))
		return ;
	if (!(*a))
	{
		*a = *b;
		*b = (*b)->next;
		(*a)->next = NULL;
	}
	else
	{
		new_node = lstnew((*b)->value, (*b)->index);
		lstadd_front(a, new_node);
		curr = *b;
		*b = (*b)->next;
		free(curr);
	}
	ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*new_node;
	t_stack	*curr;

	if (!(*a))
		return ;
	if (!(*b))
	{
		*b = *a;
		*a = (*a)->next;
		(*b)->next = NULL;
	}
	else
	{
		new_node = lstnew((*a)->value, (*a)->index);
		lstadd_front(b, new_node);
		curr = *a;
		*a = (*a)->next;
		free(curr);
	}
	ft_printf("pb\n");
}
