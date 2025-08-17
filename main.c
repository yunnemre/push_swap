#include "libft/libft.h"
#include "push_swap.h"


int main(int argc, char **argv)
{
	t_stack *stack_a = NULL;
	//printf("argc%dargc",argc);

	if (argc == 1 || (2 == argc && !argv[1][0]))
		return (1);
	//else if (argc == 2)
	parse_args(argc, argv, &stack_a);
	
	while (stack_a->next != NULL)
	{
		printf("index:%d , value : %d \n" ,stack_a->index,stack_a->value);
		stack_a = stack_a->next;
		free(stack_a->prev);
	}
	
	return(0);
}