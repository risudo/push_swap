#include "push_swap.h"

void	make_stack_a(t_dclist **stack_a, t_data *data_a, int argc, char **argv)
{
	int			i;
	t_dclist	*tmp;
	int			*p_value;

	i = 1;
	while (i < argc)
	{
		p_value = ft_atoi(argv[i]);
		if (!p_value)
			put_error();
		tmp = ft_lstnew(*p_value);
		ft_lstadd_back(stack_a, tmp);
		i++;
	}
	(void)data_a;
	push_data(stack_a, data_a);
}

void	ft_lstadd_back(t_dclist **list, t_dclist *new)
{
	t_dclist	*p;

	if (!*list)
	{
		*list = new;
		return ;
	}
	p = ft_lstlast(*list);
	(*list)->prev = new;
	p->next = new;
	new->prev = p;
	new->next = (*list);
}

t_dclist	*ft_lstlast(t_dclist *list)
{
	t_dclist	*p;

	p = list;
	while (list->next != p)
	{
		list = list->next;
	}
	return (list);
}

t_dclist	*ft_lstnew(int value)
{
	t_dclist	*new;

	new = (t_dclist *)malloc(sizeof(t_dclist));
	if (!new)
		put_error();
	new->value = value;
	new->next = new;
	new->prev = new;
	return (new);
}
