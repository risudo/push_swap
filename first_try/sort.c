#include "push_swap.h"

void	sort_stack_b(t_list **stack_a, t_list **stack_b, t_deta *deta)
{
	int	cnt_pa;

	if (deta->len == 1)
		return ;
	else if (deta->len == 2)
	{
		if ((*stack_b)->value > (*stack_b)->next->value)
			command(SB, stack_a, stack_b);
	}
	else if (deta->len == 3)
		sort_three_stack_b(stack_a, stack_b, deta);
	else
	{
		cnt_pa = pa_small_node(stack_a, stack_b, deta);
		sort_three_stack_b(stack_a, stack_b, deta);
			printf("cnt_pa: %d\n", cnt_pa);
		while (cnt_pa)
		{
			command(PB, stack_a, stack_b);
			cnt_pa--;
		}
	}
	put_stack(*stack_a, *stack_b);
}

void	sort_three_stack_b(t_list **stack_a, t_list **stack_b, t_deta *deta)
{
	if ((*stack_b)->next->next->value == deta->max && (*stack_b)->next->value == deta->min)
		command(SB, stack_a, stack_b);
	else if ((*stack_b)->value == deta->max && (*stack_b)->next->value == deta->min)
		command(RB, stack_a, stack_b);
	else if ((*stack_b)->next->next->value == deta->min && (*stack_b)->next->value == deta->max)
		command(RRB, stack_a, stack_b);
	else if ((*stack_b)->value == deta->min && (*stack_b)->next->value == deta->max)
	{
		command(SB, stack_a, stack_b);
		command(RB, stack_a, stack_b);
	}
	else if ((*stack_b)->value == deta->max && (*stack_b)->next->next->value == deta->min)
	{
		command(SB, stack_a, stack_b);
		command(RRB, stack_a, stack_b);
	}
}

int	pa_small_node(t_list **stack_a, t_list **stack_b, t_deta *deta)
{
	int	cnt;

	cnt = 0;
	while (deta->len > 3)
	{
		while ((*stack_b)->value != deta->min)
		{
			if (deta->min_place == FORMER)
				command(RB, stack_a, stack_b);
			else
				command(RRB, stack_a, stack_b);
		}
		command(PA, stack_a, stack_b);
		push_deta(stack_b, deta);
		cnt++;
	}
	put_stack(*stack_a, *stack_b);
	return (cnt);
}

void	push_swap(t_list **stack_a, t_list **stack_b, t_deta *deta)
{
		printf("---push_swap---\n");
	if (is_sorted(stack_a, stack_b, deta))
		return ;
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