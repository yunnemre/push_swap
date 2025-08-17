#include "push_swap.h"
// add_front add_back fonksiyonalrı delone fonksiyonu amybe size or last
// liste bası iicn kontrol eklememli miiym 

t_stack	*ft_stack_new(int value, t_stack *prev)
{
	t_stack *node;
	
	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return NULL;
	node->value = value;
	if (prev != NULL)
		node->index = prev->index + 1;
	else
		node->index = 1;
	node->prev = prev;
	node->next = NULL;
	return (node);
}

void	ft_stack_add_back(t_stack **lst, t_stack *new)
{
	t_stack	*temp;

	temp = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while ((*lst)->next != NULL)
	{
		*lst = (*lst)->next;
	}
	(*lst)->next = new;
	*lst = temp;
}

void	ft_stack_add_front(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}

t_stack	*ft_stack_last(t_stack *stc)
{
	if (!stc)
		return (NULL);
	while (stc->next != NULL)
	{
		stc = stc->next;
	}
	return (stc);
}
