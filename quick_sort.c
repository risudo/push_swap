#include "push_swap.h"

void	quick_sort(t_dclist **stack_a, t_dclist **stack_b, t_tdata *data)
{
	if (is_sorted(stack_a, stack_b, data->data_a))
	{
		ft_exit_success(data);
		return ;
	}
	while (data->data_b->len > 5)
	{
		if (push_min_ifpossible(stack_a, stack_b, data))
			continue ;
		pa_less_pivot(stack_a, stack_b, data);
	}
	while (push_min_ifpossible(stack_a, stack_b, data))
		;
	sortb_five(stack_a, stack_b, data);
	pb_same_status(stack_a, stack_b, data);
	push_both_data(stack_a, stack_b, data);
	quick_sort(stack_a, stack_b, data);
}

void	ft_exit_success(t_tdata *data)
{
	optimize_cmdlist(data);
	put_cmd_list(data);
}

//Aの先頭、Bの先頭、Bの２番目、Bの後ろに最小があったらの後ろにPUSH
bool	push_min_ifpossible(t_dclist **stack_a, t_dclist **stack_b, t_tdata *data)
{
	int	min;

	min = (*stack_a)->prev->c_num + 1;
		// printf("----push_min_ifpossible---\n");
	if ((*stack_a)->c_num == min)
	{
		(*stack_a)->status = SORTED;
		command(RA, stack_a, stack_b, data);
	}
	else if ((*stack_a)->next->c_num == min)
	{
		command(SA, stack_a, stack_b, data);
		(*stack_a)->status = SORTED;
		command(RA, stack_a, stack_b, data);
	}
	else if (is_stack(stack_b) && (*stack_b)->c_num == min)
	{
		(*stack_b)->status = SORTED;
		command(PA, stack_a, stack_b, data);
		command(RA, stack_a, stack_b, data);
	}
	else if (is_stack(stack_b) && (*stack_b)->next->c_num == min)
	{
		command(RB, stack_a, stack_b, data);
		(*stack_b)->status = SORTED;
		command(PA, stack_a, stack_b, data);
		command(RA, stack_a, stack_b, data);

	}
	else if (is_stack(stack_b) && (*stack_b)->prev->c_num == min)
	{
		command(RRB, stack_a, stack_b, data);
		command(PA, stack_a, stack_b, data);
		(*stack_a)->status = SORTED;
		command(RA, stack_a, stack_b, data);
	}
	else
		return (false);
	push_both_data(stack_a, stack_b, data);
		// printf("---success---\n");
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
		command(PB, stack_a, stack_b, data);
	}
	while (push_min_ifpossible(stack_a, stack_b, data))
		;
}

void	pa_less_pivot(t_dclist **stack_a, t_dclist **stack_b, t_tdata *data)
{
	int	pivot;
	int i;
	int	cnt;

	i = 0;
	cnt = 0;
		// printf("---pa_less_pivot---\n");
	push_data(stack_b, data->data_b);
	pivot = get_pivot(stack_b, data->data_b);
	while (is_stack(stack_b) && i < data->data_b->len && cnt < pivot - data->data_b->min_c_num + 1)
	{
		// if (push_min_ifpossible(stack_a, stack_b, data))
		// 	continue ;
// !ここでやるとバグる
		if ((*stack_b)->c_num > pivot)
		{
			cnt++;
			(*stack_b)->status++;
			command(PA, stack_a, stack_b, data);
		}
		else
			command(RB, stack_a, stack_b, data);
		i++;
	}
	push_data(stack_b, data->data_b);
}
//Aの未ソートのpivot以下をPBする
//TODO: SORTED以外で最小値を見つけたらRA

void	pb_less_pivot(t_dclist **stack_a, t_dclist **stack_b, t_tdata *data)
{
	int	pivot;
	int	cnt;
	int	next_min;

	cnt = 0;
		// printf("---pb_less_pivot---\n");
	next_min = (*stack_a)->prev->c_num + 1;
	push_data(stack_a, data->data_a);
	pivot = get_pivot(stack_a, data->data_a);
	while ((*stack_a)->status != SORTED && cnt < pivot - data->data_a->min_c_num + 1)
	{
		if ((*stack_a)->c_num <= pivot)
		{
			cnt++;
			command(PB, stack_a, stack_b, data);
		}
		else
			command(RA, stack_a, stack_b, data);
	}
	while ((*stack_a)->prev->status != SORTED)
		command(RRA, stack_a, stack_b, data);
}

int	get_pivot(t_dclist **stack, t_data *data)
{
	int	min;
//c_numの最小値と最大値をとる！
	if ((*stack)->prev->status == SORTED)
		min = (*stack)->prev->c_num + 1;
	else
		min = data->min_c_num;
	return ((data->max_c_num + min) / 2);
}

void	pa_ra_sortedb(t_dclist **stack_a, t_dclist **stack_b, t_tdata *data)
{
		// printf("---pb_less_pivot---\n");
	while (is_stack(stack_b))
	{
		(*stack_b)->status = SORTED;
		command(PA, stack_a, stack_b, data);
		command(RA, stack_a, stack_b, data);
	}
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
		if (data->data_b->min_place == FORMER)
			cmd = RB;
		else if (data->data_b->min_place == LATTER)
			cmd = RRB;
		while ((*stack_b)->c_num != data->data_b->min_c_num)
			command(cmd, stack_a, stack_b, data);
		(*stack_b)->status = SORTED;
		command(PA, stack_a, stack_b, data);
		command(RA, stack_a, stack_b, data);
		push_data(stack_b, data->data_b);
	}
	if (!bis_sorted(stack_b, data->data_b))
		sortb_three(stack_a, stack_b, data);
	while (is_stack(stack_b))
	{
		(*stack_b)->status = SORTED;
		command(PA, stack_a, stack_b, data);
		command(RA, stack_a, stack_b, data);
	}
}
