/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:48:33 by ydinler           #+#    #+#             */
/*   Updated: 2025/08/26 21:19:40 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	ft_sort_b(t_stack **stack_b)
{
	if (*stack_b && (*stack_b)->next)
	{
		if ((*stack_b)->value < (*stack_b)->next->value)
			sb(*stack_b, 1);
	}
}

void	ft_check_bigger(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*last;

	last = ft_stack_last(*stack_a);
	if ((*stack_a)->value < (*stack_a)->next->value)
	{
		if ((*stack_a)->value < last->value)
			pb(stack_a, stack_b);
		else
		{
			rra(stack_a, 1);
			pb(stack_a, stack_b);
		}
	}
	else
	{
		sa(*stack_a, 1);
		if ((*stack_a)->value < last->value)
			pb(stack_a, stack_b);
		else
		{
			rra(stack_a, 1);
			pb(stack_a, stack_b);
		}
	}
}

void	ft_bubble(t_stack **stack_a, t_stack **stack_b, int raunt)
{
	int	size;

	size = ft_stack_size(*stack_a);
	if (size > 2 && raunt)
	{
		ft_check_bigger(stack_a, stack_b);
		ft_sort_b(stack_b);
		ft_bubble(stack_a, stack_b, 1);
	}
	else
	{
		while (ft_stack_size(*stack_b))
		{
			pa(stack_a, stack_b);
		}
	}
}
