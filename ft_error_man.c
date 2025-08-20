/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_man.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 18:41:20 by ydinler           #+#    #+#             */
/*   Updated: 2025/08/21 02:11:06 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error_man(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a && *stack_a)
		ft_stack_clear(stack_a);
	if (stack_b && *stack_b)
		ft_stack_clear(stack_b);
	write(2, "Error\n", 6);
	exit(1);
}
