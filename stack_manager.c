/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 14:50:13 by ydinler           #+#    #+#             */
/*   Updated: 2025/08/28 17:58:14 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_new(int value)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = 0;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	ft_stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*temp;

	temp = *stack;
	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new;
	new->prev = temp;
}

void	ft_stack_add_front(t_stack **stack, t_stack *new)
{
	if (*stack != NULL)
		(*stack)->prev = new;
	new->prev = NULL;
	new->next = *stack;
	*stack = new;
}

t_stack	*ft_stack_last(t_stack *stc)
{
	if (!stc)
		return (NULL);
	while (stc->next != NULL)
		stc = stc->next;
	return (stc);
}

void	ft_stack_clear(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}
