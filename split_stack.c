#include "push_swap.h"

void	first_sort(t_dclist **stack_a, t_dclist **stack_b, t_tdata *data)
{
	command(RRB, stack_a, stack_b, data);
	command(RRB, stack_a, stack_b, data);
	command(RRB, stack_a, stack_b, data);
	if ((*stack_b)->c_num == 1)
		pa_ra(stack_a, stack_b, data);
	else if ((*stack_b)->next->c_num == 1)
	{
		command(PA, stack_a, stack_b, data);
		command(PA, stack_a, stack_b, data);
		(*stack_a)->status = SORTED;
		command(RA, stack_a, stack_b, data);
	}
	else if ((*stack_b)->next->next->c_num == 1)
	{
		command(PA, stack_a, stack_b, data);
		command(PA, stack_a, stack_b, data);
		command(PA, stack_a, stack_b, data);
		(*stack_a)->status = SORTED;
		command(RA, stack_a, stack_b, data);
	}
}

void	pb_less_ave(t_dclist **stack_a, t_dclist **stack_b, t_tdata *data)
{
	int	i;
	int	pivot;

	i = -1;
	pivot = data->data_a->len / 2 + 1;
	while (++i < data->data_a->len)
	{
		if ((*stack_a)->c_num == 1 || (*stack_a)->c_num == 2 || (*stack_a)->c_num == 3)
		{
			command(PB, stack_a, stack_b, data);
			if ((*stack_b)->next != (*stack_b))
				command(RB, stack_a, stack_b, data);
		}
		else if ((*stack_a)->c_num <= pivot)
			command(PB, stack_a, stack_b, data);
		else
			command(RA, stack_a, stack_b, data);
	}
	first_sort(stack_a, stack_b, data);
	// command(RRB, stack_a, stack_b, data);
	// command(RRB, stack_a, stack_b, data);
	// if ((*stack_b)->c_num > (*stack_b)->next->c_num)
	// 	command(SB, stack_a, stack_b, data);
	// pa_ra(stack_a, stack_b, data);
	// pa_ra(stack_a, stack_b, data);
}


void	split_stack(t_dclist **stack_a, t_dclist **stack_b, t_tdata *data)
{
	if (is_sorted(stack_a, stack_b, data->data_a))
		return ;
	pb_less_ave(stack_a, stack_b, data);
	push_both_data(stack_a, stack_b, data);
	// if (data->data_a->len <= 5 && data->data_b->len <= 5)
	// {
	// 	push_swap(stack_a, stack_b, data);
	// 		exit(0);
	// 	sortb_ascending(stack_a, stack_b, data);
	// 	return ;
	// }
	quick_sort(stack_a, stack_b, data);
}
