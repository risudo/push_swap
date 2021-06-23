#include "push_swap.h"

void	quick_sort(t_dclist **stack_a, t_dclist **stack_b, t_tdata *data)
{
	if (data->data_b->len <= 5)
	{
		sortb_less_five(stack_a, stack_b, data->data_b);
		// Aの後ろにpush
		// stage = SORTED
	}

}

void	sortb_less_five(t_dclist **stack_a, t_dclist **stack_b, t_data *data_b)
{
	if (bis_sorted(stack_b, data_b))
		return;
	else if (data_b->len == 2)
		command(SB, stack_a, stack_b);
	else if (data_b->len == 3)
		sortb_three(stack_a, stack_b, data_b);
	else
		sortb_five(stack_a, stack_b, data_b);
}

void	sortb_three(t_dclist **stack_a, t_dclist **stack_b, t_data *data_b)
{
	if ((*stack_b)->next->next->value == data_b->max
		&& (*stack_b)->next->value == data_b->min)
		command(SB, stack_a, stack_b);
	else if ((*stack_b)->value == data_b->max
		&& (*stack_b)->next->value == data_b->min)
		command(RB, stack_a, stack_b);
	else if ((*stack_b)->next->next->value == data_b->min
		&& (*stack_b)->next->value == data_b->max)
		command(RRB, stack_a, stack_b);
	else if ((*stack_b)->value == data_b->min
		&& (*stack_b)->next->value == data_b->max)
	{
		command(SB, stack_a, stack_b);
		command(RB, stack_a, stack_b);
	}
	else if ((*stack_b)->value == data_b->max
		&& (*stack_b)->next->next->value == data_b->min)
	{
		command(SB, stack_a, stack_b);
		command(RRB, stack_a, stack_b);
	}
}

void	sortb_five(t_dclist **stack_a, t_dclist **stack_b, t_data *data_b)
{
	int	cmd;

	while (data_b->len != 3)
	{
		if (data_b->min_place == FORMER)
			cmd = RB;
		else if (data_b->min_place == LATTER)
			cmd = RRB;
		while ((*stack_b)->value != data_b->min)
			command(cmd, stack_a, stack_b);
		command(PA, stack_a, stack_b);
		command(RA, stack_a, stack_b);
		push_data(stack_b, data_b);
	}
	sortb_three(stack_a, stack_b, data_b);

}