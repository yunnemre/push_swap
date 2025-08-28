/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:45:36 by ydinler           #+#    #+#             */
/*   Updated: 2025/08/28 18:18:32 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_bit(int index, int round)
{
	return ((index >> round) & 1);
}

void	ft_return_b(t_stack **stack_a, t_stack **stack_b)
{
	while (ft_stack_size(*stack_b))
		pa(stack_a, stack_b);
}

void	ft_radix(t_stack **stack_a, t_stack **stack_b)
{
	int	round;
	int	size;
	int	r2;
	int	max_bit;

	size = ft_stack_size(*stack_a);
	round = 0;
	max_bit = 0;
	while (((size - 1) >> max_bit) != 0)
		max_bit++;
	while (round < max_bit)
	{
		r2 = size;
		while (r2--)
		{
			if (check_bit((*stack_a)->index, round))
				ra(stack_a, 1);
			else
				pb(stack_a, stack_b);
		}
		ft_return_b(stack_a, stack_b);
		if (ft_is_sorted(*stack_a))
			return ;
		round++;
	}
}
