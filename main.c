/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 14:50:24 by ydinler           #+#    #+#             */
/*   Updated: 2025/08/28 18:20:44 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	ft_is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (!(stack->value < stack->next->value))
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sort_three(t_stack **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->value;
	b = (*stack_a)->next->value;
	c = ft_stack_last(*stack_a)->value;
	if (a > b && b < c && a < c)
		sa(*stack_a, 1);
	else if (a > b && b > c)
	{
		sa(*stack_a, 1);
		rra(stack_a, 1);
	}
	else if (a > b && b < c && a > c)
		ra(stack_a, 1);
	else if (a < b && b > c && a < c)
	{
		sa(*stack_a, 1);
		ra(stack_a, 1);
	}
	else if (a < b && b > c && a > c)
		rra(stack_a, 1);
}

void	push_min_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		min;

	while (ft_stack_size(*stack_a) > 3)
	{
		tmp = *stack_a;
		min = tmp->value;
		while (tmp)
		{
			if (min > tmp->value)
				min = tmp->value;
			tmp = tmp->next;
		}
		while ((*stack_a)->value != min)
			ra(stack_a, 1);
		pb(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int		size;

	if (ft_is_sorted(*stack_a))
		return ;
	size = ft_stack_size(*stack_a);
	if (size == 1)
		return ;
	else if (size == 2)
	{
		sa(*stack_a, 1);
		return ;
	}
	else if (size == 3)
		sort_three(stack_a);
	else if (size <= 5)
		push_min_b(stack_a, stack_b);
	else
		ft_radix(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || (2 == argc && !argv[1][0]))
		return (1);
	else if (argc >= 2)
		parse_args(argc, argv, &stack_a);
	assign_index(stack_a);
	push_swap(&stack_a, &stack_b);
	ft_stack_clear(&stack_a);
	ft_stack_clear(&stack_b);
	return (0);
}
