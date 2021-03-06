#include "push_swap.h"

bool	is_sorted(t_dclist **stack_a, t_dclist **stack_b, t_data *data_a)
{
	int	tmp;
	int	i;

	if (is_stack(stack_b))
		return (false);
	i = -1;
	tmp = (*stack_a)->value;
	while (++i < data_a->len)
	{
		if (tmp > (*stack_a)->value)
			data_a->sorted_len = 0;
		tmp = (*stack_a)->value;
		(*stack_a) = (*stack_a)->next;
		data_a->sorted_len++;
	}
	if (data_a->sorted_len == data_a->len)
		return (true);
	else
		return (false);
}

bool	bis_sorted(t_dclist **stack_b, t_data *data_b)
{
	int			i;
	int			tmp;
	t_dclist	*p;

	i = 0;
	p = (*stack_b);
	tmp = (*stack_b)->value;
	while (i < data_b->len)
	{
		if (tmp > (*stack_b)->value)
		{
			(*stack_b) = p;
			return (false);
		}
		tmp = (*stack_b)->value;
		(*stack_b) = (*stack_b)->next;
		i++;
	}
	return (true);
}

bool	is_stack(t_dclist **stack)
{
	if (*stack)
		return (true);
	else
		return (false);
}

int	get_pivot(t_dclist **stack, t_data *data)
{
	int	min;

	if ((*stack)->prev->status == SORTED)
		min = (*stack)->prev->order + 1;
	else
		min = data->min_order;
	return ((data->max_order + min) / 2);
}
