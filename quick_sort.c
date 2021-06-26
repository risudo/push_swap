#include "push_swap.h"


void	quick_sort(t_dclist **stack_a, t_dclist **stack_b, t_tdata *data)
{
	if (is_sorted(stack_a, stack_b, data->data_a))
		return ;
	while (data->data_b->len > 5)
	{
		pa_less_pivot(stack_a, stack_b, data->data_b);
	}
	//BをソートしてPA,RA
	sortb_five(stack_a, stack_b, data->data_b);
	//Aの先頭statusと同じやつをPB
	pb_same_status(stack_a, stack_b);
	//5個以下になるまでPA
	push_both_data(stack_a, stack_b, data);
	quick_sort(stack_a, stack_b, data);
}

void	pb_same_status(t_dclist **stack_a, t_dclist **stack_b)
{
	int	status;

	status = (*stack_a)->status;
	while (status == (*stack_a)->status && status != SORTED)
		command(PB, stack_a, stack_b);
}

void	pa_less_pivot(t_dclist **stack_a, t_dclist **stack_b, t_data *data_b)
{
	int	pivot;
	int i;

	i = 0;
	push_data(stack_b, data_b);
	// pivot = data_b->len / 2;
	pivot = get_pivot(stack_b, data_b);
	while (i < data_b->len)
	{
		if ((*stack_b)->c_num > pivot)
		{
			(*stack_b)->status++;
			command(PA, stack_a, stack_b);
		}
		else
			command(RB, stack_a, stack_b);
		i++;
	}
	push_data(stack_b, data_b);
}
//Aの未ソートのpivot以下をPBする
void	pb_less_pivot(t_dclist **stack_a, t_dclist **stack_b, t_tdata *data)
{
	int	pivot;
	int	i;

	i = 0;
	push_data(stack_a, data->data_a);
	pivot = get_pivot(stack_a, data->data_a);
	while (i < data->data_a->len && (*stack_a)->status != SORTED)
	{
		if ((*stack_a)->c_num <= pivot)
			command(PB, stack_a, stack_b);
		else
			command(RA, stack_a, stack_b);
	}
	while ((*stack_a)->prev->status != SORTED)
		command(RRA, stack_a, stack_b);
	exit(0);
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

// void	sort_11arg(t_dclist **stack_a, t_dclist **stack_b, t_tdata *data)
// {
// 	int pivot;

// 	sortb_five(stack_a, stack_b, data->data_b);
// 	push_data(stack_a, data->data_a);
// 	pivot = (data->data_a->len + (*stack_a)->prev->c_num + 1) / 2;
// 	printf("debug\n");
// 		exit(0);
// 	while ((*stack_a)->status != SORTED)
// 	{
// 		if ((*stack_a)->c_num <= pivot)
// 			command(PB, stack_a, stack_b);
// 		else
// 			command(RA, stack_a, stack_b);
// 	}
// 	while ((*stack_a)->prev->status != SORTED)
// 		command(RRA, stack_a, stack_b);
// 	push_both_data(stack_a, stack_b, data);
// 	sortb_three(stack_a, stack_b, data->data_b);
// 	pa_ra_sortedb(stack_a, stack_b);
// 	while ((*stack_a)->status != SORTED)
// 		command(PB, stack_a, stack_b);
// 	push_both_data(stack_a, stack_b, data);
// 	sortb_three(stack_a, stack_b, data->data_b);
// 	pa_ra_sortedb(stack_a, stack_b);
// }

void	pa_ra_sortedb(t_dclist **stack_a, t_dclist **stack_b)
{
	while (is_stack(stack_b))
	{
		(*stack_b)->status = SORTED;
		command(PA, stack_a, stack_b);
		command(RA, stack_a, stack_b);
	}
}


void	sortb_three(t_dclist **stack_a, t_dclist **stack_b, t_data *data_b)
{
	// push_data(stack_b, data_b);
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

	push_data(stack_b, data_b);
	while (data_b->len != 3)
	{
		if (data_b->min_place == FORMER)
			cmd = RB;
		else if (data_b->min_place == LATTER)
			cmd = RRB;
		while ((*stack_b)->value != data_b->min)
			command(cmd, stack_a, stack_b);
		(*stack_b)->status = SORTED;
		command(PA, stack_a, stack_b);
		command(RA, stack_a, stack_b);
		push_data(stack_b, data_b);
	}
	sortb_three(stack_a, stack_b, data_b);
	while (is_stack(stack_b))
	{
		(*stack_b)->status = SORTED;
		command(PA, stack_a, stack_b);
		command(RA, stack_a, stack_b);
	}
}