#include "push_swap.h"

void	numbering_list(t_dclist **stack_a, t_data *data_a)
{
	int	i;
	int	min_cmp;
	int	next_min;

	min_cmp = data_a->min;
	int j = -1;
	while (++j < data_a->len)
	{
		next_min = data_a->max;
		i = 0;
		while (i < data_a->len)
		{
			if ((*stack_a)->value > min_cmp)
				(*stack_a)->c_num++;
			if ((*stack_a)->value < next_min && (*stack_a)->value > min_cmp)
				next_min = (*stack_a)->value;
			(*stack_a) = (*stack_a)->next;
			i++;
		}
		min_cmp = next_min;
	}
}