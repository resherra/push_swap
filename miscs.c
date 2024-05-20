/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miscs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:26:15 by recherra          #+#    #+#             */
/*   Updated: 2024/05/20 16:50:03 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void	ft_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

void	init(t_holder *holder, t_stack *stack_a)
{
	holder->a = stack_a->value;
	holder->b = stack_a->next->value;
	holder->c = stack_a->next->next->value;
}

void	check_overflow(int num, int flag)
{
	if (num > 0 && flag == 2)
		ft_error();
	if (num < 0 && flag == 1)
		ft_error();
}
