/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_rev_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 09:42:09 by ydinler           #+#    #+#             */
/*   Updated: 2025/08/28 17:47:43 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	rev_rotate_man(t_stack **stack)
{
	t_stack	*last;
	t_stack	*tmp;

	if (ft_stack_size(*stack) <= 1)
		return (0);
	last = ft_stack_last(*stack);
	tmp = last->prev;
	tmp->next = NULL;
	ft_stack_add_front(stack, last);
	return (1);
}

void	rra(t_stack **stack_a, int ptsd)
{
	int	res;

	res = rev_rotate_man(stack_a);
	if (ptsd && res)
		ft_printf("rra\n");
}

void	rrb(t_stack **stack_b, int ptsd)
{
	int	res;

	res = rev_rotate_man(stack_b);
	if (ptsd && res)
		ft_printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b, int ptsd)
{
	int	ra_done;
	int	rb_done;

	ra_done = rev_rotate_man(stack_a);
	rb_done = rev_rotate_man(stack_b);
	if (ptsd && (ra_done || rb_done))
		ft_printf("rrr\n");
}