#include "push_swap.h"

void	pb_less_ave(t_dclist **stack_a, t_dclist **stack_b, t_data *data_a)
{
	int	i;
	int	pivot;

	i = 0;
	pivot = data_a->len / 2;
	while (i < data_a->len)
	{
		if ((*stack_a)->c_num <= pivot)
			command(PB, stack_a, stack_b);
		else
			command(RA, stack_a, stack_b);
		i++;
	}
}
//平均以下をPBして、AとB両方とも5個以下ならソートして連結
void	split_stack(t_dclist **stack_a, t_dclist **stack_b, t_tdata *data)
{
	if (is_sorted(stack_a, stack_b, data->data_a))
		return ;
	pb_less_ave(stack_a, stack_b, data->data_a);
	push_both_data(stack_a, stack_b, data);
	if (data->data_a->len <= 5 && data->data_b->len <= 5)
	{
		push_swap(stack_a, stack_b, data);
		sortb_ascending(stack_a, stack_b, data->data_b);
		return ;
	}
	// else if (data->data_b->len <= 5)
	// {
	// 	sort_11arg(stack_a, stack_b, data);
	// 	return ;
	// }
	quick_sort(stack_a, stack_b, data);
}


	// 		1. 平均以下をPB
	// 		2. （スタックBが６個以上ならBの平均以上をPA）
	// →→	3. スタックBが５個以下になったらソート

	// ↑	4. PA->RA
	// ↑←	5. 2でPAしたノードをPB