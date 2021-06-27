#include "push_swap.h"

void	init_stack_a(t_dclist **stack_a, t_data *data_a, int argc, char **argv)
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
	push_data(stack_a, data_a);
	numbering_list(stack_a, data_a);
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
		list = list->next;
	return (list);
}

t_dclist	*ft_lstnew(int value)
{
	t_dclist	*new;

	new = (t_dclist *)malloc(sizeof(t_dclist));
	if (!new)
		put_error();
	new->value = value;
	new->status = 0;
	new->c_num = 1;
	new->next = new;
	new->prev = new;
	return (new);
}

void	numbering_list(t_dclist **stack_a, t_data *data_a)
{
	int	i;
	int	j;
	int	min_cmp;
	int	next_min;

	i = 0;
	min_cmp = data_a->min;
	while (i < data_a->len)
	{
		next_min = data_a->max;
		j = 0;
		while (j < data_a->len)
		{
			if ((*stack_a)->value > min_cmp)
				(*stack_a)->c_num++;
			if ((*stack_a)->value < next_min && (*stack_a)->value > min_cmp)
				next_min = (*stack_a)->value;
			(*stack_a) = (*stack_a)->next;
			j++;
		}
		min_cmp = next_min;
		i++;
	}
}
