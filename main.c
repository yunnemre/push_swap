/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 14:50:24 by ydinler           #+#    #+#             */
/*   Updated: 2025/08/21 01:04:28 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
// https://medium.com/@ayogun/push-swap-c1f5d2d41e97
// https://www.youtube.com/watch?v=wRvipSG4Mmk
// https://medium.com/@ulysse.gks/push-swap-in
//-less-than-4200-operations-c292f034f6c0
// https://www.youtube.com/watch?v=OaG81sDEpVk

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	//t_stack	*stack_b;
	t_stack	*tmp;

	stack_a = NULL;
	//stack_b = NULL;
	if (argc == 1 || (2 == argc && !argv[1][0]))
		return (1);
	else if (argc >= 2)
		parse_args(argc, argv, &stack_a);
	tmp = stack_a;
	assign_index(stack_a);
	ss(stack_a,1);
	while (stack_a)
	{
		printf("index:%d , value : %d \n", stack_a->index, stack_a->value);
		stack_a = stack_a->next;
	}
	
	ft_stack_clear(&tmp);
	return (0);
}
