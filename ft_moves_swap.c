/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 20:50:07 by ydinler           #+#    #+#             */
/*   Updated: 2025/08/21 21:24:55 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	swap_man(t_stack *stack)
{
	int	tmp_v;
	int	tmp_i;
	
	if (stack && stack->next)
	{
		tmp_v = stack->value;
		tmp_i = stack->index;
		stack->value = stack->next->value;
		stack->index = stack->next->index;
		stack->next->value = tmp_v;
		stack->next->index = tmp_i;
		return (1);
	}
	return (0);
}

int	sa(t_stack *stack_a, int ptsd)
{
	int	res;
	
	res = swap_man(stack_a);
	if (ptsd && res)
            ft_printf("sa\n");
	if (res)
		return(1);
	return (0);
}

int	sb(t_stack *stack_b, int ptsd)
{
	int	res;

	res = swap_man(stack_b);
	if (ptsd && res)
            ft_printf("sb\n");
	if (res)
		return(1);
	return (0);
	
}

void	ss(t_stack *stack_a, t_stack *stack_b, int ptsd)
{
	int sa_done;
	int sb_done;
	
	sa_done = swap_man(stack_a);
	sb_done = swap_man(stack_b);
    if (ptsd && (sa_done || sb_done))
            ft_printf("ss\n");
}
