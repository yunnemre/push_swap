/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 14:50:19 by ydinler           #+#    #+#             */
/*   Updated: 2025/08/26 20:02:15 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

/*STACK*/
t_stack	*ft_stack_new(int value, t_stack *prev);
void	ft_stack_add_back(t_stack **lst, t_stack *new);
void	ft_stack_add_front(t_stack **lst, t_stack *new);
void	ft_stack_clear(t_stack **stack);
void	parse_args(int argc, char **argv, t_stack **a);
t_stack	*ft_stack_last(t_stack *stc);
void	ft_del_res(char **res);
int		ft_create_stack(char **res, t_stack **a);
void	assign_index(t_stack *stack_a);
void	ft_bubble_sort(int *arr, int arry_size);
int		ft_stack_size(t_stack *stack);
void	swap(int *arr, int i, int j);
int		ft_atoi_v2(const char *nptr, int *out);
void	ft_error_man(t_stack **stack_a, t_stack **stack_b);
int		ft_dup_checks(t_stack *stack_a, int value);

/*MOVES*/
int		swap_man(t_stack *stack);
void	sa(t_stack *stack_a, int ptsd);
void	sb(t_stack *stack_b, int ptsd);
void	ss(t_stack *stack_a, t_stack *stack_b, int ptsd);

void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);

int		rotate_man(t_stack **stack);
void	ra(t_stack **stack_a, int ptsd);
void	rb(t_stack **stack_b, int ptsd);
void	rr(t_stack **stack_a, t_stack **stack_b, int ptsd);

int		rev_rotate_man(t_stack **stack);
void	rra(t_stack **stack_a, int ptsd);
void	rrb(t_stack **stack_b, int ptsd);
void	rrr(t_stack **stack_a, t_stack **stack_b, int ptsd);

int		ft_is_sorted(t_stack *stack);

void	ft_bubble(t_stack **stack_a, t_stack **stack_b, int raunt);
void	ft_check_bigger(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_b(t_stack **stack_b);

int		check_bit(int	value, int raunt);
void	ft_return_b(t_stack **stack_a, t_stack **stack_b);
void	ft_radix(t_stack **stack_a, t_stack **stack_b);
#endif
