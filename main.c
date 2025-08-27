/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 14:50:24 by ydinler           #+#    #+#             */
/*   Updated: 2025/08/26 22:15:18 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
// https://medium.com/@ayogun/push-swap-c1f5d2d41e97
// https://www.youtube.com/watch?v=wRvipSG4Mmk
// https://medium.com/@ulysse.gks/push-swap-in
//-less-than-4200-operations-c292f034f6c0
// https://www.youtube.com/watch?v=OaG81sDEpVk

int	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int		size;

	size = ft_stack_size(*stack_a);
	(void)stack_b;
	if (size == 1)
		return (1);
	
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*tmp;
	int		is_sort;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || (2 == argc && !argv[1][0]))
		return (1);
	else if (argc >= 2)
		parse_args(argc, argv, &stack_a);
	assign_index(stack_a);
	
	
	// while (!is_sort)
	// {
	// 	is_sort=ft_is_sorted(stack_a);
		
	// }
	ft_radix(&stack_a, &stack_b);
	is_sort = ft_is_sorted(stack_a);
	if (is_sort)
	{
		printf("sort olmus diyor");
	}
	else
		printf("sort oolmamıs diyor");
	tmp = stack_a;
	// while (stack_a)
	// {
	// 	printf("STACK AA: index:%d , value : %d \n",
	// 		stack_a->index, stack_a->value);
	// 	stack_a = stack_a->next;
	// }
	ft_stack_clear(&tmp);
	ft_stack_clear(&stack_b);
	return (0);
}

// while (stack_a)
	// {
	// 	printf("STACK AA: index:%d , value : %d \n",
	// 		stack_a->index, stack_a->value);
	// 	stack_a = stack_a->next;
	// }
// if (stack_a->prev)
// 		{
// 			printf("##STACK AA: index:%d , value : %d \n",
// 				stack_a->prev->index, stack_a->prev->value);
//}