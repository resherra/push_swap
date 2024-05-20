/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 15:42:34 by recherra          #+#    #+#             */
/*   Updated: 2024/05/20 16:50:17 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

int	ft_atoi_basic(const char *str)
{
	int	number;
	int	sign;
	int	i;

	number = 0;
	sign = 0;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		number = (number * 10) + (str[i++] - 48);
	if (str[i])
		ft_error();
	if (sign == 1)
		return (-number);
	return (number);
}

void	is_sorted(t_stack *stack_a)
{
	t_stack	*curr;
	t_stack	*tes;

	curr = stack_a;
	while (curr)
	{
		tes = curr;
		while (tes)
		{
			if (curr->value > tes->value)
				return ;
			tes = tes->next;
		}
		curr = curr->next;
	}
	exit(1);
}

void	check(char *str, int *flag)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '-' || str[i] == '+'))
		{
			if (str[i] == '-')
				(*flag)++;
			if (str[i + 1] < '0' || str[i + 1] > '9')
				ft_error();
		}
		else if (str[i] < '0' || str[i] > '9')
			ft_error();
		i++;
	}
	(*flag)++;
}

void	is_repeated(t_stack **stack_a, int value)
{
	t_stack	*curr;

	curr = *stack_a;
	while (curr->next)
	{
		if (curr->value == value)
			ft_error();
		curr = curr->next;
	}
}

typedef struct s_utils
{
	int	flag;
	int	num;
}		t_utils;

void	sanitize(char *str, t_stack **stack_a)
{
	static int	j;
	int			i;
	char		**res;
	t_utils		utils;
	t_stack		*new;

	i = 0;
	res = ft_split(str, ' ');
	if (res == NULL)
		exit(1);
	while (res[i])
	{
		utils.flag = 0;
		check(res[i], &utils.flag);
		utils.num = ft_atoi_basic(res[i]);
		check_overflow(utils.num, utils.flag);
		new = lstnew(utils.num, j);
		lstadd_back(stack_a, new);
		j++;
		is_repeated(stack_a, utils.num);
		free(res[i]);
		i++;
	}
	free(res);
}
