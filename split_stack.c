#include "push_swap.h"

void	pb_less_ave(t_dclist **stack_a, t_dclist **stack_b, t_tdata *data)
{
	int	i;
	int	pivot;

	i = 0;
	pivot = data->data_a->len / 2;
	while (i < data->data_a->len)
	{
		if ((*stack_a)->c_num == 1)
		{
			(*stack_a)->status = SORTED;
			command(PB, stack_a, stack_b, data);
			command(RB, stack_a, stack_b, data);
		}
		else if ((*stack_a)->c_num <= pivot)
			command(PB, stack_a, stack_b, data);
		else
			command(RA, stack_a, stack_b, data);
		i++;
	}
	command(RRB, stack_a, stack_b, data);
	command(PA, stack_a, stack_b, data);
	command(RA, stack_a, stack_b, data);
}
//平均以下をPBして、AとB両方とも5個以下ならソートして連結
void	split_stack(t_dclist **stack_a, t_dclist **stack_b, t_tdata *data)
{
	if (is_sorted(stack_a, stack_b, data->data_a))
		return ;
	pb_less_ave(stack_a, stack_b, data);
	push_both_data(stack_a, stack_b, data);
	if (data->data_a->len <= 5 && data->data_b->len <= 5)
	{
		push_swap(stack_a, stack_b, data);
		sortb_ascending(stack_a, stack_b, data);
		return ;
	}
	// push_min_ifpossible(stack_a, stack_b, data);
	// exit(0);
	quick_sort(stack_a, stack_b, data);
}
