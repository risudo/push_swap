#include "push_swap.h"

void	sortb_ascending(t_dclist **stack_a, t_dclist **stack_b, t_data *data_b)
{

	if (data_b->len == 3)
	{
		sortb_ascending_three(stack_a, stack_b, data_b);
		return ;
	}
	while (data_b->len != 3)
	{
		while ((*stack_b)->value != data_b->max)
			command(RB, stack_a, stack_b);
		command(PA, stack_a, stack_b);
		push_data(stack_b, data_b);
	}
	sortb_ascending_three(stack_a, stack_b, data_b);
	while (is_stack(stack_b))
		command(PA, stack_a, stack_b);
}

void	sortb_ascending_three(t_dclist **stack_a, t_dclist **stack_b, t_data *data_b)
{
	if ((*stack_b)->next->next->value == data_b->max
		&& (*stack_b)->next->value == data_b->min)
		command(RRB, stack_a, stack_b);
	else if ((*stack_b)->value == data_b->max
		&& (*stack_b)->next->value == data_b->min)
	{
		command(SB, stack_a, stack_b);
		command(RB, stack_a, stack_b);
	}
	else if ((*stack_b)->next->next->value == data_b->min
		&& (*stack_b)->next->value == data_b->max)
		command(SB, stack_a, stack_b);
	else if ((*stack_b)->value == data_b->min
		&& (*stack_b)->next->value == data_b->max)
		command(RB, stack_a, stack_b);
	else if ((*stack_b)->value == data_b->min
		&& (*stack_b)->next->next->value == data_b->max)
	{
		command(SB, stack_a, stack_b);
		command(RRB, stack_a, stack_b);
	}
}