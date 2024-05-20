/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:56:48 by recherra          #+#    #+#             */
/*   Updated: 2024/05/20 16:52:38 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "libft/libft.h"

typedef struct s_stack
{
	int				value;
	unsigned int	index;
	struct s_stack	*next;
}					t_stack;

typedef struct s_holder
{
	int				a;
	int				b;
	int				c;
}					t_holder;

//miscs
void				ft_error(void);
void				init(t_holder *holder, t_stack *stack_a);
void				check_overflow(int num, int flag);

//act sorting
void				sort_three(t_stack **stack_a);
void				sort_five(t_stack **stack_a, t_stack **stack_b);

//lst utils
t_stack				*lstnew(int number, int index);
int					lst_size(t_stack *stack);
void				lstadd_back(t_stack **lst, t_stack *new);
void				lstadd_front(t_stack **lst, t_stack *new);
void				swap(t_stack **stack);

//parsing utils
void				check(char *str, int *flag);
void				is_repeated(t_stack **stack_a, int value);
void				is_sorted(t_stack *stack_a);
void				sanitize(char *str, t_stack **stack_a);

//pre sort utils
void				sort_arr(int *arr, int len);
void				act_index(t_stack *stack, int *arr, int len);
void				index_stack(t_stack *stack);

//stack_utils
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
void				rotate(t_stack **stack);
void				rev_rotate(t_stack **stack);
