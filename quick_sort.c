#include "push_swap.h"

void	quick_sort(t_dclist **stack_a, t_dclist **stack_b, t_tdata *data)
{
	bool	push;

	push = false;
	if (is_sorted(stack_a, stack_b, data->data_a))
		return ;
	while (data->data_b->len > 5)
		push = pa_more_pivot(stack_a, stack_b, data);
	if (!push && data->data_b->min_c_num == (*stack_a)->prev->c_num + 1)
		sortb_five(stack_a, stack_b, data);
	pb_same_status(stack_a, stack_b, data);
	push_both_data(stack_a, stack_b, data);
	quick_sort(stack_a, stack_b, data);
}

bool	push_min_ifpossible(t_dclist **stack_a,
				t_dclist **stack_b, t_tdata *data)
{
	int	min;
		// printf("----push_min_ifpossible---\n");
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
	else if (is_stack(stack_b) && (*stack_b)->next->next->c_num == min)
		rb_sb_pa_ra(stack_a, stack_b, data);
	else if (is_stack(stack_b) && (*stack_b)->prev->prev->prev->c_num == min)
		rrb_rrb_rrb_pa_ra(stack_a, stack_b, data);
	else if (is_stack(stack_b) && (*stack_b)->prev->prev->prev->prev->c_num == min)
		rrb_rrb_rrb_rrb_pa_ra(stack_a, stack_b, data);
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
		// printf("---pb_same_status---\n");
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

bool	pa_more_pivot(t_dclist **stack_a, t_dclist **stack_b, t_tdata *data)
{
	int		pivot;
	int		i;
	int		cnt;
	bool	ret;

	init_variable(&i, &cnt, &ret);
	push_data(stack_b, data->data_b);
	pivot = get_pivot(stack_b, data->data_b);
	while (is_stack(stack_b) && ++i < data->data_b->len
			&& cnt < pivot - data->data_b->min_c_num + 1)
	{
		while (push_min_ifpossible(stack_a, stack_b, data))
			ret = true;
		if (is_stack(stack_b) && (*stack_b)->c_num > pivot)
		{
			cnt++;
			(*stack_b)->status++;
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

void	sortb_three(t_dclist **stack_a, t_dclist **stack_b, t_tdata *data)
{
	if ((*stack_b)->next->next->c_num == data->data_b->max_c_num
		&& (*stack_b)->next->c_num == data->data_b->min_c_num)
		command(SB, stack_a, stack_b, data);
	else if ((*stack_b)->c_num == data->data_b->max_c_num
		&& (*stack_b)->next->c_num == data->data_b->min_c_num)
		command(RB, stack_a, stack_b, data);
	else if ((*stack_b)->next->next->c_num == data->data_b->min_c_num
		&& (*stack_b)->next->c_num == data->data_b->max_c_num)
		command(RRB, stack_a, stack_b, data);
	else if ((*stack_b)->c_num == data->data_b->min_c_num
		&& (*stack_b)->next->c_num == data->data_b->max_c_num)
	{
		command(SB, stack_a, stack_b, data);
		command(RB, stack_a, stack_b, data);
	}
	else if ((*stack_b)->c_num == data->data_b->max_c_num
		&& (*stack_b)->next->next->c_num == data->data_b->min_c_num)
	{
		command(SB, stack_a, stack_b, data);
		command(RRB, stack_a, stack_b, data);
	}
}

void	sortb_five(t_dclist **stack_a, t_dclist **stack_b, t_tdata *data)
{
	int	cmd;
		// printf("---sortb_five---\n");//
	if (!is_stack(stack_b))
		return ;
	push_data(stack_b, data->data_b);
	while (data->data_b->len != 3)
	{
		cmd = RRB;
		if (data->data_b->min_place == FORMER)
			cmd = RB;
		while ((*stack_b)->c_num != data->data_b->min_c_num)
			command(cmd, stack_a, stack_b, data);
		pa_ra(stack_a, stack_b, data);
		push_data(stack_b, data->data_b);
	}
	if (!bis_sorted(stack_b, data->data_b))
		sortb_three(stack_a, stack_b, data);
	while (is_stack(stack_b) && (*stack_b)->c_num == (*stack_a)->prev->c_num + 1)
		pa_ra(stack_a, stack_b, data);
}
