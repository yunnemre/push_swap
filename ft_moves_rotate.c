/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 22:39:08 by ydinler           #+#    #+#             */
/*   Updated: 2025/08/28 17:47:59 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	rotate_man(t_stack **stack)
{
	t_stack	*tmp;

	if (ft_stack_size(*stack) <= 1)
		return (0);
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	(*stack)->prev = NULL;
	ft_stack_add_back(stack, tmp);
	return (1);
}

void	ra(t_stack **stack_a, int ptsd)
{
	int	res;

	res = rotate_man(stack_a);
	if (ptsd && res)
		ft_printf("ra\n");
}

void	rb(t_stack **stack_b, int ptsd)
{
	int	res;

	res = rotate_man(stack_b);
	if (ptsd && res)
		ft_printf("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b, int ptsd)
{
	int	ra_done;
	int	rb_done;

	ra_done = rotate_man(stack_a);
	rb_done = rotate_man(stack_b);
	if (ptsd && (ra_done || rb_done))
		ft_printf("rr\n");
}
