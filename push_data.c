#include "push_swap.h"

void	update_value(t_dclist **stack, t_data *data, int cnt)
{
	if (data->min > (*stack)->value)
	{
		data->min_place = cnt + 1;
		data->min = (*stack)->value;
	}
	if (data->max < (*stack)->value)
		data->max = (*stack)->value;
}

void	push_data(t_dclist **stack, t_data *data)
{
	t_dclist	*p;
	int			cnt;

	cnt = 0;
	data->sorted_len = 0;
	p = (*stack);
	data->max = (*stack)->value;
	data->min = (*stack)->value;
	while ((*stack)->next != p)
	{
		update_value(stack, data, cnt);
		cnt++;
		(*stack) = (*stack)->next;
	}
	update_value(stack, data, cnt);
	data->len = cnt + 1;
	if (data->len / 2 >= data->min_place
		|| (data->len == 5 && data->min_place == 3))
		data->min_place = FORMER;
	else
		data->min_place = LATTER;
	data->average = (data->min + data->max) / 2;
	(*stack) = p;
}

void	push_both_data(t_dclist **stack_a, t_dclist **stack_b, t_tdata *data)
{
	push_data(stack_a, data->data_a);
	push_data(stack_b, data->data_b);
}