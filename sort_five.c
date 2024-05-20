/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:34:45 by recherra          #+#    #+#             */
/*   Updated: 2024/05/20 16:49:42 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

typedef struct s_position
{
	int		size;
	int		tmp;
}			t_position;

static void	check_min(t_stack *curr, int *min, int *index)
{
	while (curr)
	{
		if (curr->value < *min)
		{
			*min = curr->value;
			*index = curr->index;
		}
		curr = curr->next;
	}
}

static void	operate(t_stack **stack_a, int index, int tmp, int min)
{
	if (index < tmp)
	{
		while ((*stack_a)->value != min)
			rotate(stack_a);
	}
	else
	{
		while ((*stack_a)->value != min)
			rev_rotate(stack_a);
	}
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int			i;
	int			min;
	int			index;
	t_stack		*curr;
	t_position	position_in_list;

	i = 0;
	while (i < 2)
	{
		curr = *stack_a;
		min = (*stack_a)->value;
		index = (*stack_a)->index;
		check_min(curr, &min, &index);
		position_in_list.size = lst_size(*stack_a) - 1;
		position_in_list.tmp = position_in_list.size / 2;
		operate(stack_a, index, position_in_list.tmp, min);
		pb(stack_a, stack_b);
		i++;
	}
	sort_three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}
