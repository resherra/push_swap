/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:21:08 by recherra          #+#    #+#             */
/*   Updated: 2024/05/20 19:40:15 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

int	count_bits(unsigned int n)
{
	int	count;

	count = 0;
	while (n)
	{
		count++;
		n = n >> 1;
	}
	return (count);
}

void	check_max(t_stack *curr, unsigned int *max)
{
	while (curr)
	{
		if (curr->index > *max)
			*max = curr->index;
		curr = curr->next;
	}
}

typedef struct s_i_j
{
	int	i;
	int	j;
}		t_i_j;

void	radix(t_stack **stack_a, t_stack **stack_b)
{
	static t_i_j		incre;
	t_stack				*curr;
	int					size;
	static unsigned int	max;
	int					max_bits;

	curr = *stack_a;
	check_max(curr, &max);
	max_bits = count_bits(max);
	while (incre.i < max_bits)
	{
		incre.j = 0;
		size = lst_size(*stack_a);
		while (incre.j < size)
		{
			if (((((*stack_a)->index) >> incre.i) & 1) == 0)
				pb(stack_a, stack_b);
			else
				rotate(stack_a);
			incre.j++;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		incre.i++;
	}
}

int	main(int ac, char **av)
{
	int		i;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = NULL;
	stack_a = NULL;
	i = 1;
	if (ac == 1)
		return (0);
	if (!ft_strlen(av[i]))
		ft_error();
	while (av[i])
		sanitize(av[i++], &stack_a);
	is_sorted(stack_a);
	if (lst_size(stack_a) == 2)
		swap(&stack_a);
	else if (lst_size(stack_a) == 3)
		sort_three(&stack_a);
	else if (lst_size(stack_a) == 5)
		sort_five(&stack_a, &stack_b);
	else
	{
		index_stack(stack_a);
		radix(&stack_a, &stack_b);
	}
}
