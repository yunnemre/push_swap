/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 14:50:19 by ydinler           #+#    #+#             */
/*   Updated: 2025/08/20 02:23:12 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

t_stack	*ft_stack_new(int value, t_stack *prev);
void	ft_stack_add_back(t_stack **lst, t_stack *new);
void	ft_stack_add_front(t_stack **lst, t_stack *new);
void	ft_stack_clear(t_stack **stack);
void	parse_args(int argc, char **argv, t_stack **a);
t_stack	*ft_stack_last(t_stack *stc);
void	ft_del_res(char **res);
int		ft_create_stack(char **res, t_stack	**tmp, t_stack **a);
void	assign_index(t_stack *stack_a);
void	ft_bubble_sort(int *arr, int arry_size);
void	swap(int *arr, int i, int j);
#endif
