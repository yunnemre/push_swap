#include "libft/libft.h"
#include "push_swap.h"

void parse_args(int argc, char **argv, t_stack **a)
{
	char 	**res;
	t_stack *tmp;
	t_stack *new;
	int		ss;
	int		i;
	
	i = 1;
	tmp = NULL;

	while (i < argc)
	{
		res = ft_split(argv[i], ' ');
		int j=0;
		while (res[j])
		{
			ss = ft_atoi(res[j]);
			if (!tmp)
			{
				(*a) = ft_stack_new(ss, NULL);
				tmp = *a;
			}
			else
			{
				new =ft_stack_new(ss, ft_stack_last(*a));
				ft_stack_add_back(a,new);
			}
			j++;
		}
		j=0;
		while (res[j])
		{
			free(res[j]);
			res[j]=NULL;
			j++;
		}
		free(res);
		i++;
	}
	*a= tmp;
}