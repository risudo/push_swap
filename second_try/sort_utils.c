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
		// put_stack(*stack_a, *stack_b);
	}
	if (data_a->sorted_len == data_a->len)
		return (true);
	else
		return (false);
}

bool	is_stack(t_dclist **stack)
{
	if (*stack)
		return (true);
	else
		return (false);
}
