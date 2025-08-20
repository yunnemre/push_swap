/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 01:37:53 by ydinler           #+#    #+#             */
/*   Updated: 2025/08/21 02:11:03 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_size(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*start;
	t_stack	*tmp;
	int		size;
	
	size = ft_stack_size(stack_b);
	if (size == 0)
		return ;
		
	tmp = (*stack_b)->next;
	(*stack_b)->next = *stack_a;
	
	if (*stack_a)
		(*stack_a)->prev = *stack_b;
		
	(*stack_b)->prev = NULL;
	*stack_a = *stack_b;
	*stack_b = tmp;
	
	if (*stack_b)
		(*stack_b)->prev = NULL;
		
	ft_printf("pa\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*start;
	t_stack	*tmp;
	int		size;
	
	size = ft_stack_size(stack_b);
	if (size == 0)
		return ;
		
	tmp = (*stack_a)->next;
	(*stack_a)->next = *stack_b;
	
	if (*stack_b)
		(*stack_b)->prev = *stack_a;
		
	(*stack_a)->prev = NULL;
	*stack_b = *stack_a;
	*stack_a = tmp;
	
	if (*stack_a)
		(*stack_a)->prev = NULL;
		
	ft_printf("pb\n");
}