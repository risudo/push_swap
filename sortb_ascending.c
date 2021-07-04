#include "push_swap.h"

// void	sortb_ascending(t_dclist **stack_a, t_dclist **stack_b, t_tdata *data)
// {
// 	exit(0);
// 	while (data->data_b->len != 3)
// 	{
// 		while ((*stack_b)->value != data->data_b->max)
// 			command(RB, stack_a, stack_b, data);
// 		command(PA, stack_a, stack_b, data);
// 		push_data(stack_b, data->data_b);
// 	}
// 	sortb_ascending_three(stack_a, stack_b, data);
// 	while (is_stack(stack_b))
// 		command(PA, stack_a, stack_b, data);
// }

// void	sortb_ascending_three(t_dclist **stack_a, t_dclist **stack_b, t_tdata *data)
// {
// 	if ((*stack_b)->next->next->order == data->data_b->max_c_num
// 		&& (*stack_b)->next->order == data->data_b->min_c_num)
// 		command(RRB, stack_a, stack_b, data);
// 	else if ((*stack_b)->order == data->data_b->max_c_num
// 		&& (*stack_b)->next->order == data->data_b->min_c_num)
// 	{
// 		command(SB, stack_a, stack_b, data);
// 		command(RB, stack_a, stack_b, data);
// 	}
// 	else if ((*stack_b)->next->next->order == data->data_b->min_c_num
// 		&& (*stack_b)->next->order == data->data_b->max_c_num)
// 		command(SB, stack_a, stack_b, data);
// 	else if ((*stack_b)->order == data->data_b->min_c_num
// 		&& (*stack_b)->next->order == data->data_b->max_c_num)
// 		command(RB, stack_a, stack_b, data);
// 	else if ((*stack_b)->order == data->data_b->min_c_num
// 		&& (*stack_b)->next->next->order == data->data_b->max_c_num)
// 	{
// 		command(SB, stack_a, stack_b, data);
// 		command(RRB, stack_a, stack_b, data);
// 	}
// }
