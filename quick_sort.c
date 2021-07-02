#include "push_swap.h"

void	quick_sort(t_dclist **stack_a, t_dclist **stack_b, t_tdata *data)
{
	if (is_sorted(stack_a, stack_b, data->data_a))
		return ;
	while (data->data_b->len > 5
		&& data->data_b->min_c_num == (*stack_a)->prev->c_num + 1)
		pa_more_pivot(stack_a, stack_b, data);
	pb_same_status(stack_a, stack_b, data);
	push_both_data(stack_a, stack_b, data);
	quick_sort(stack_a, stack_b, data);
}

bool	push_min_ifpossible(t_dclist **stack_a,
				t_dclist **stack_b, t_tdata *data)
{
	int	min;

	min = (*stack_a)->prev->c_num + 1;
	if ((*stack_a)->c_num == min)
		ra(stack_a, stack_b, data);
	else if ((*stack_a)->next->c_num == min)
		sa_ra(stack_a, stack_b, data);
	else if (is_stack(stack_b) && (*stack_b)->c_num == min)
		pa_ra(stack_a, stack_b, data);
	else if (is_stack(stack_b) && (*stack_b)->next->c_num == min)
		sb_pa_ra(stack_a, stack_b, data);
	else if (is_stack(stack_b) && (*stack_b)->prev->c_num == min)
		rrb_pa_ra(stack_a, stack_b, data);
	else if (is_stack(stack_b) && (*stack_b)->prev->prev->c_num == min)
		rrb_rrb_pa_ra(stack_a, stack_b, data);
	// else if (is_stack(stack_b) && (*stack_b)->next->next->c_num == min)
	// 	rb_sb_pa_ra(stack_a, stack_b, data);
	else if (is_stack(stack_b) && (*stack_b)->prev->prev->prev->c_num == min)
		rrb_rrb_rrb_pa_ra(stack_a, stack_b, data);
	else
	{
		if (is_stack(stack_b) && (*stack_b)->next != (*stack_b) && (*stack_b)->c_num == min + 1)
			command(RB, stack_a, stack_b, data);
		return (false);
	}
	push_both_data(stack_a, stack_b, data);
	return (true);
}

void	pb_same_status(t_dclist **stack_a, t_dclist **stack_b, t_tdata *data)
{
	int	status;

	status = (*stack_a)->status;

	if (status == SORTED)
		return ;
	while (status == (*stack_a)->status)
	{
		if (push_min_ifpossible(stack_a, stack_b, data))
			continue ;
		(*stack_a)->status = 0;
		command(PB, stack_a, stack_b, data);
	}
	while (push_min_ifpossible(stack_a, stack_b, data))
		;
}

void	init_variable(int *i, int *cnt, bool *ret)
{
	*i = -1;
	*cnt = 0;
	*ret = false;
}

bool	is_large_num(t_dclist **stack_b, t_data *data_b, int pivot)
{
	push_data(stack_b, data_b);
	if (data_b->max_c_num > pivot)
		return (true);
	else
		return (false);
}

bool	pa_more_pivot(t_dclist **stack_a, t_dclist **stack_b, t_tdata *data)
{
	int		pivot;
	int		i;
	bool	ret;

	i = -1;
	ret = false;
	push_data(stack_b, data->data_b);
	pivot = get_pivot(stack_b, data->data_b);
	while (is_stack(stack_b) && ++i < data->data_b->len
			 && is_large_num(stack_b, data->data_b, pivot))
	{
		while (push_min_ifpossible(stack_a, stack_b, data))
			ret = true;
		if (is_stack(stack_b) && (*stack_b)->c_num > pivot)
		{
			(*stack_b)->status += pivot;
			command(PA, stack_a, stack_b, data);
		}
		else if (is_stack(stack_b) && ret == false)
			command(RB, stack_a, stack_b, data);
	}
	push_both_data(stack_a, stack_b, data);
	return (ret);
}

int	get_pivot(t_dclist **stack, t_data *data)
{
	int	min;

	if ((*stack)->prev->status == SORTED)
		min = (*stack)->prev->c_num + 1;
	else
		min = data->min_c_num;
	return ((data->max_c_num + min) / 2);
}
