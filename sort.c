#include "push_swap.h"

void	push_swap(t_list **stack_a, t_list **stack_b, t_deta *deta)
{
	// if (is_sorted(stack_a))
	// 	return ;
	if (deta->len <= 3)
		sort_three(stack_a, stack_b, deta);
	else if (deta->len <= 6)
	{
		recursive_pb(stack_a, stack_b, deta);
		sort_three(stack_a, stack_b, deta);
		while (is_stack(stack_b))
			command(PA, stack_a, stack_b);
	}
	else
		quick_sort(stack_a, stack_b, deta);
}

void	recursive_pb(t_list **stack_a, t_list **stack_b, t_deta *deta)
{
	int	cmd;

	if (deta->len == 3)
	{
		return ;
	}
	if (deta->min_place == FORMER)
		cmd = RA;
	else
		cmd = RRA;
	while ((*stack_a)->value != deta->min)
		command(cmd, stack_a, stack_b);
	command(PB, stack_a, stack_b);
	push_deta(stack_a, deta);
	recursive_pb(stack_a, stack_b, deta);
}

void	sort_three_node(t_list **stack_a, t_list **stack_b, t_deta *deta)
{
	if ((*stack_a)->next->next->value == deta->max && (*stack_a)->next->value == deta->min)
		command(SA, stack_a, stack_b);
	else if ((*stack_a)->value == deta->max && (*stack_a)->next->value == deta->min)
		command(RA, stack_a, stack_b);
	else if ((*stack_a)->next->next->value == deta->min && (*stack_a)->next->value == deta->max)
		command(RRA, stack_a, stack_b);
	else if ((*stack_a)->value == deta->min && (*stack_a)->next->value == deta->max)
	{
		command(SA, stack_a, stack_b);
		command(RA, stack_a, stack_b);
	}
	else if ((*stack_a)->value == deta->max && (*stack_a)->next->next->value == deta->min)
	{
		command(SA, stack_a, stack_b);
		command(RRA, stack_a, stack_b);
	}
}

void	sort_three(t_list **stack_a, t_list **stack_b, t_deta *deta)
{
	if (deta->len == 1)
		return ;
	if (deta->len == 2)
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
		{
			command(SA, stack_a, stack_b);
		}
		return ;
	}
	sort_three_node(stack_a, stack_b, deta);
}