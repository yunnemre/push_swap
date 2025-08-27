/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 17:22:55 by ydinler           #+#    #+#             */
/*   Updated: 2025/08/27 01:35:52 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	ft_stack_size(t_stack *stack_a)
{
	int	size;

	size = 0;
	if (!stack_a)
		return (0);
	while (stack_a)
	{
		size++;
		stack_a = stack_a->next;
	}
	return (size);
}

void	swap(int *arr, int i, int j)
{
	int	temp;

	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void	ft_bubble_sort(int *arr, int arry_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < arry_size - 1)
	{
		j = 0;
		while (j < arry_size - i - 1)
		{
			if (arr[j] > arr[j + 1])
				swap(arr, j, j + 1);
			j++;
		}
		i++;
	}
}

void	ft_set_index(t_stack *stack_a, int *arr, int arry_size)
{
	int	i;

	while (stack_a)
	{
		i = 0;
		while (i < arry_size)
		{
			if (stack_a->value == arr[i])
			{
				stack_a->index = i;
				break ;
			}
			i++;
		}
		stack_a = stack_a->next;
	}
}

void	assign_index(t_stack *stack_a)
{
	t_stack	*tmp;
	int		*arr;
	int		i;
	int		arry_size;

	i = 0;
	tmp = stack_a;
	arry_size = ft_stack_size(stack_a);
	arr = malloc(sizeof(int) * arry_size);
	while (tmp)
	{
		arr[i] = tmp->value;
		i++;
		tmp = tmp->next;
	}
	ft_bubble_sort(arr, arry_size);
	ft_set_index(stack_a, arr, arry_size);
	free(arr);
}
