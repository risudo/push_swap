#include "push_swap.h"

void	put_stack(t_dclist *stack_a, t_dclist *stack_b)
{
	t_dclist	*p_a;
	t_dclist	*p_b;
	int		i;

	i = 1;
	p_a = stack_a;
	p_b = stack_b;
	printf("---a---\n");
	if (!stack_a)
	{
		printf("(null)\n");
		goto STAC_B;
	}
	while (stack_a ->next != p_a)
	{
		printf("i: %d\tvalue: %d\tc_num: %d\tstatus: %d\n", i, stack_a->value, stack_a->c_num, stack_a->status);
		stack_a = stack_a->next;
		i++;
	}
	printf("i: %d\tvalue: %d\tc_num: %d\tstatus: %d\n", i, stack_a->value, stack_a->c_num, stack_a->status);
	// printf("\n");
	// while (stack_a != p_a)
	// {
	// 	printf("i: %d\tvalue: %d\n", i, stack_a->value);
	// 	stack_a = stack_a->prev;
	// 	i--;
	// }
	// printf("i: %d\tvalue: %d\n", i, stack_a->vlue);
	printf("\n");
	i = 1;

STAC_B:
	printf("---b---\n");
	if (!stack_b)
	{
		printf("(null)\n\n");
		return ;
	}
	while (stack_b ->next != p_b)
	{
		printf("i: %d\tvalue: %d\tc_num: %d\tstatus: %d\n", i, stack_b->value, stack_b->c_num, stack_b->status);
		stack_b = stack_b->next;
		i++;
	}
	printf("i: %d\tvalue: %d\tc_num: %d\tstatus: %d\n", i, stack_b->value, stack_b->c_num, stack_b->status);
	printf("\n");
	// while (stack_b != p_b)
	// {
	// 	printf("i: %d\tvalue: %ld\n", i, stack_b->value);
	// 	stack_b = stack_b->prev;
	// 	i--;
	// }
	// printf("i: %d\tvalue: %ld\n", i, stack_b->value);
	// printf("\n");
}

void	put_data(t_data *data)
{
	printf("max: %d\n", data->max);
	printf("min: %d\n", data->min);
	printf("min_c_num: %d\n", data->min_c_num);
	printf("max_c_num: %d\n", data->max_c_num);
	printf("len: %d\n", data->len);
	if (data->min_place == FORMER)
		printf("min_place: FORMER\n");
	else if (data->min_place == LATTER)
		printf("min_place: LATTER\n");
	printf("sorted_len: %d\n", data->sorted_len);
}

void	put_cmd_list(t_tdata *data)
{
	t_list	*cmdlist;

	cmdlist = data->cmd_list;
	printf("---command list---\n");
	while (cmdlist->next != NULL)
	{
		put_command(cmdlist->cmd);
		cmdlist = cmdlist->next;
	}
	put_command(cmdlist->cmd);
}