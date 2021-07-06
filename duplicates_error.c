#include "push_swap.h"

void	duplicates_error(t_dclist **stack_a, t_dclist **stack_b, t_tdata *data)
{
	int	i;

	i = 0;
	while (i < data->data_a->len)
	{
		if ((*stack_a)->next != (*stack_a)
			&& (*stack_a)->value == (*stack_a)->next->value)
		{
			stackclear(stack_a, stack_b, data);
			put_error();
		}
		(*stack_a) = (*stack_a)->next;
		i++;
	}
}
