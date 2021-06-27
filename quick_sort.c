#include "push_swap.h"


void	quick_sort(t_dclist **stack_a, t_dclist **stack_b, t_tdata *data)
{
	if (is_sorted(stack_a, stack_b, data->data_a))
		return ;
	while (data->data_b->len > 5)
	{
		pa_less_pivot(stack_a, stack_b, data);
	}
	//BをソートしてPA,RA
	sortb_five(stack_a, stack_b, data);
	//Aの先頭statusと同じやつをPB
	pb_same_status(stack_a, stack_b, data);
	//5個以下になるまでPA
	push_both_data(stack_a, stack_b, data);
	quick_sort(stack_a, stack_b, data);
}

void	pb_same_status(t_dclist **stack_a, t_dclist **stack_b, t_tdata *data)
{
	int	status;

	status = (*stack_a)->status;
	while (status == (*stack_a)->status && status != SORTED)
		command(PB, stack_a, stack_b, data);
}

void	pa_less_pivot(t_dclist **stack_a, t_dclist **stack_b, t_tdata *data)
{
	int	pivot;
	int i;
	int	cnt;

//TODO: 必要な分PAしたらbreakさせる！
	i = 0;
	cnt = 0;
	push_data(stack_b, data->data_b);
	pivot = get_pivot(stack_b, data->data_b);
	while (i < data->data_b->len && cnt < pivot - data->data_b->min_c_num + 1)
	{
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
void	pb_less_pivot(t_dclist **stack_a, t_dclist **stack_b, t_tdata *data)
{
	int	pivot;
	int	i;
	int	cnt;
//TODO: 必要な分PBしたらbreakさせる
	i = 0;
	cnt = 0;
	push_data(stack_a, data->data_a);
	pivot = get_pivot(stack_a, data->data_a);
	while (i < data->data_a->len && (*stack_a)->status != SORTED && cnt < pivot - data->data_a->min_c_num + 1)
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
	// exit(0);
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

void	pa_ra_sortedb(t_dclist **stack_a, t_dclist **stack_b, t_tdata *data)
{
	while (is_stack(stack_b))
	{
		(*stack_b)->status = SORTED;
		command(PA, stack_a, stack_b, data);
		command(RA, stack_a, stack_b, data);
	}
}


void	sortb_three(t_dclist **stack_a, t_dclist **stack_b, t_tdata *data)
{
	// push_data(stack_b, data_b);
	if ((*stack_b)->next->next->value == data->data_b->max
		&& (*stack_b)->next->value == data->data_b->min)
		command(SB, stack_a, stack_b, data);
	else if ((*stack_b)->value == data->data_b->max
		&& (*stack_b)->next->value == data->data_b->min)
		command(RB, stack_a, stack_b, data);
	else if ((*stack_b)->next->next->value == data->data_b->min
		&& (*stack_b)->next->value == data->data_b->max)
		command(RRB, stack_a, stack_b, data);
	else if ((*stack_b)->value == data->data_b->min
		&& (*stack_b)->next->value == data->data_b->max)
	{
		command(SB, stack_a, stack_b, data);
		command(RB, stack_a, stack_b, data);
	}
	else if ((*stack_b)->value == data->data_b->max
		&& (*stack_b)->next->next->value == data->data_b->min)
	{
		command(SB, stack_a, stack_b, data);
		command(RRB, stack_a, stack_b, data);
	}
}

void	sortb_five(t_dclist **stack_a, t_dclist **stack_b, t_tdata *data)
{
	int	cmd;

	push_data(stack_b, data->data_b);
	while (data->data_b->len != 3)
	{
		if (data->data_b->min_place == FORMER)
			cmd = RB;
		else if (data->data_b->min_place == LATTER)
			cmd = RRB;
		while ((*stack_b)->value != data->data_b->min)
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