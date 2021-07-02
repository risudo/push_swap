#include "push_swap.h"

//not integers, bigger than an integer, duplicates
//TODO:被りエラーチェック

void	ft_lstadd_front(t_dclist **list, t_dclist *new)
{
	t_dclist	*p;

	if (!*list)
	{
		*list = new;
		return ;
	}
	p = ft_lstlast(*list);
	new->next = *list;
	(*list)->prev = new;
	p->next = new;
	new->prev = p;
	*list = new;
}

void	put_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	push_swap(t_dclist **stack_a, t_dclist **stack_b, t_tdata *data)
{
	push_data(stack_a, data->data_a);
	if (is_sorted(stack_a, stack_b, data->data_a))
		return ;
	else if (data->data_a->len == 2)
		command(SA, stack_a, stack_b, data);
	else if (data->data_a->len == 3)
		sort_three_arg(stack_a, stack_b, data);
	else if (data->data_a->len <= 5)
		sort_five_arg(stack_a, stack_b, data);
	else
		split_stack(stack_a, stack_b, data);
	push_both_data(stack_a, stack_b, data);
	return ;
}

int	main(int argc, char **argv)
{
	t_dclist	*stack_a;
	t_dclist	*stack_b;
	t_data		data_a;
	t_data		data_b;
	t_tdata		stack_data;

	stack_data.data_a = &data_a;
	stack_data.data_b = &data_b;
	if (argc == 1)
		put_error();
	init_stack_a(&stack_a, stack_data.data_a, argc, argv);
	push_swap(&stack_a, &stack_b, &stack_data);
	optimize_cmdlist(&stack_data);
	put_cmd_list(&stack_data);
	ft_stackclear(&stack_a, &stack_b, &stack_data);
	cmd_clear(stack_data.cmd_list);
	return (0);
}
//? 引数１の時は何も表示しないが正解？