/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 14:49:59 by ydinler           #+#    #+#             */
/*   Updated: 2025/08/27 17:11:00 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	ft_dup_checks(t_stack *stack_a, int value)
{
	while (stack_a)
	{
		if (stack_a->value == value)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

int	ft_create_stack(char **res, t_stack **a)
{
	t_stack	*new;
	int		ss;
	int		i;

	i = 0;
	while (res[i])
	{
		if (!ft_atoi_v2(res[i], &ss))
			return (1);
		if (ft_dup_checks(*a, ss))
			return (1);
		new = ft_stack_new(ss);
		if (!new)
			return (1);
		ft_stack_add_back(a, new);
		i++;
	}
	return (0);
}

void	ft_del_res(char **res)
{
	int		j;

	j = 0;
	while (res[j])
	{
		free(res[j]);
		res[j] = NULL;
		j++;
	}
	free(res);
}

void	parse_args(int argc, char **argv, t_stack **stack_a)
{
	char	**res;
	int		i;

	i = 1;
	while (i < argc)
	{
		res = ft_split(argv[i], ' ');
		if (!res)
			ft_error_man(stack_a, NULL);
		if (ft_create_stack(res, stack_a) || !*res)
		{
			ft_del_res(res);
			ft_error_man(stack_a, NULL);
		}
		ft_del_res(res);
		i++;
	}
}
