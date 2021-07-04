#include "push_swap.h"

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
	if (!init_stack_a(&stack_a, stack_data.data_a, argc, argv))
	{
		stackclear(&stack_a, &stack_b, &stack_data);
		put_error();
	}
	push_swap(&stack_a, &stack_b, &stack_data);
	duplicates_error(&stack_a, stack_data.data_a);
	optimize_cmdlist(&stack_data);
	put_cmd_list(&stack_data);
	stackclear(&stack_a, &stack_b, &stack_data);
	cmd_clear(stack_data.cmd_list);
	return (0);
}
