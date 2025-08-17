#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack {
    int value;
    int index;
    struct s_stack *next;
    struct s_stack *prev;
} t_stack;

t_stack	*ft_stack_new(int value, t_stack *prev);
void	ft_stack_add_back(t_stack **lst, t_stack *new); 
void	ft_stack_add_front(t_stack **lst, t_stack *new);
void	parse_args(int argc, char **argv, t_stack **a);
t_stack	*ft_stack_last(t_stack *stc);

#endif
