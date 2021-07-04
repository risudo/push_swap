#include "push_swap.h"

bool	init_stack_a(t_dclist **stack_a, t_data *data_a, int argc, char **argv)
{
	int			i;
	t_dclist	*tmp;
	int			*p_value;
	bool		ret;

	i = 1;
	ret = true;
	while (i < argc)
	{
		p_value = ft_atoi(argv[i]);
		if (!p_value)
		{
			ret = false;
			break ;
		}
		tmp = ft_lstnew(*p_value);
		ft_lstadd_back(stack_a, tmp);
		i++;
	}
	push_data(stack_a, data_a);
	numbering_list(stack_a, data_a);
	return (ret);
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
	new->order = 1;
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

	i = -1;
	if (!data_a)
		return ;
	min_cmp = data_a->min;
	while (++i < data_a->len)
	{
		next_min = data_a->max;
		j = -1;
		while (++j < data_a->len)
		{
			if ((*stack_a)->value > min_cmp)
				(*stack_a)->order++;
			if ((*stack_a)->value < next_min && (*stack_a)->value > min_cmp)
				next_min = (*stack_a)->value;
			(*stack_a) = (*stack_a)->next;
		}
		min_cmp = next_min;
	}
}
