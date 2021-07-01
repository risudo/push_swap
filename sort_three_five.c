#include "push_swap.h"

void	sort_three_arg(t_dclist **stack_a, t_dclist **stack_b, t_tdata *data)
{
	if ((*stack_a)->next->next->c_num == data->data_a->max_c_num
		&& (*stack_a)->next->c_num == data->data_a->min_c_num)
		command(SA, stack_a, stack_b, data);
	else if ((*stack_a)->c_num == data->data_a->max_c_num
		&& (*stack_a)->next->c_num == data->data_a->min_c_num)
		command(RA, stack_a, stack_b, data);
	else if ((*stack_a)->next->next->c_num == data->data_a->min_c_num
		&& (*stack_a)->next->c_num == data->data_a->max_c_num)
		command(RRA, stack_a, stack_b, data);
	else if ((*stack_a)->c_num == data->data_a->min_c_num
		&& (*stack_a)->next->c_num == data->data_a->max_c_num)
	{
		command(SA, stack_a, stack_b, data);
		command(RA, stack_a, stack_b, data);
	}
	else if ((*stack_a)->c_num == data->data_a->max_c_num
		&& (*stack_a)->next->next->c_num == data->data_a->min_c_num)
	{
		command(SA, stack_a, stack_b, data);
		command(RRA, stack_a, stack_b, data);
	}
}

void	recursive_pb(t_dclist **stack_a, t_dclist **stack_b, t_tdata *data)
{
	int	cmd;

	if (data->data_a->len == 3)
		return ;
	if (data->data_a->min_place == FORMER)
		cmd = RA;
	else if (data->data_a->min_place == LATTER)
		cmd = RRA;
	while ((*stack_a)->c_num != data->data_a->min_c_num)
		command(cmd, stack_a, stack_b, data);
	(*stack_a)->status++;
	command(PB, stack_a, stack_b, data);
	push_data(stack_a, data->data_a);
	recursive_pb(stack_a, stack_b, data);
}

void	sort_five_arg(t_dclist **stack_a, t_dclist **stack_b, t_tdata *data)
{
	int	status;

	recursive_pb(stack_a, stack_b, data);
	sort_three_arg(stack_a, stack_b, data);
	status = (*stack_b)->status;
	while (is_stack(stack_b) && status == (*stack_b)->status)
	{
		command(PA, stack_a, stack_b, data);
		(*stack_a)->status--;
	}
}
