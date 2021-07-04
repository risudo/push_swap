#include "push_swap.h"

void	duplicates_error(t_dclist **stack_a, t_data *data_a)
{
	int	i;

	i = 0;
	while (i < data_a->len)
	{
		if ((*stack_a)->next != (*stack_a)
			&& (*stack_a)->value == (*stack_a)->next->value)
		{
			put_error();
		}
		(*stack_a) = (*stack_a)->next;
		i++;
	}
}
