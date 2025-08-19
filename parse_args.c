/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 14:49:59 by ydinler           #+#    #+#             */
/*   Updated: 2025/08/19 17:39:11 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	parse_args(int argc, char **argv, t_stack **a)
{
	char	**res;
	t_stack	*tmp;
	int		i;

	i = 1;
	tmp = NULL;
	while (i < argc)
	{
		res = ft_split(argv[i], ' ');
		if (!res)
			return ;
		if (ft_create_stack(res, &tmp, a))
		{
			ft_stack_clear(a);
			ft_del_res(res);
			return ;
		}
		ft_del_res(res);
		i++;
	}
	*a = tmp;
}

int	ft_create_stack(char **res, t_stack	**tmp, t_stack **a)
{
	t_stack	*new;
	int		ss;
	int		j;

	j = 0;
	while (res[j])
	{
		ss = ft_atoi(res[j]);
		if (!*tmp)
		{
			(*a) = ft_stack_new(ss, NULL);
			if (!*a)
				return (1);
			*tmp = *a;
		}
		else
		{
			new = ft_stack_new(ss, ft_stack_last(*a));
			if (!new)
				return (1);
			ft_stack_add_back(a, new);
		}
		j++;
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
