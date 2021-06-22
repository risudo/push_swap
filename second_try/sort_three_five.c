#include "push_swap.h"

void	sort_three_arg(t_dclist **stack_a, t_dclist **stack_b, t_data *data_a)
{
	if ((*stack_a)->next->next->value == data_a->max
		&& (*stack_a)->next->value == data_a->min)
		command(SA, stack_a, stack_b);
	else if ((*stack_a)->value == data_a->max
		&& (*stack_a)->next->value == data_a->min)
		command(RA, stack_a, stack_b);
	else if ((*stack_a)->next->next->value == data_a->min
		&& (*stack_a)->next->value == data_a->max)
		command(RRA, stack_a, stack_b);
	else if ((*stack_a)->value == data_a->min
		&& (*stack_a)->next->value == data_a->max)
	{
		command(SA, stack_a, stack_b);
		command(RA, stack_a, stack_b);
	}
	else if ((*stack_a)->value == data_a->max
		&& (*stack_a)->next->next->value == data_a->min)
	{
		command(SA, stack_a, stack_b);
		command(RRA, stack_a, stack_b);
	}
}

void	recursive_pb(t_dclist **stack_a, t_dclist **stack_b, t_data *data_a)
{
	int	cmd;

	if (data_a->len == 3)
		return ;
	if (data_a->min_place == FORMER)
		cmd = RA;
	else if (data_a->min_place == LATTER)
		cmd = RRA;
	while ((*stack_a)->value != data_a->min)
		command(cmd, stack_a, stack_b);
	command(PB, stack_a, stack_b);
	push_data(stack_a, data_a);
	recursive_pb(stack_a, stack_b, data_a);
}

void	sort_five_arg(t_dclist **stack_a, t_dclist **stack_b, t_data *data_a)
{
	recursive_pb(stack_a, stack_b, data_a);
	sort_three_arg(stack_a, stack_b, data_a);
	while (is_stack(stack_b))
		command(PA, stack_a, stack_b);
}
