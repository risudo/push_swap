#include "push_swap.h"

void	swap(t_dclist **stack)
{
	t_dclist	*stack_cpy;
	t_dclist	*next_cpy;
	t_dclist	*last;

	last = ft_lstlast(*stack);
	stack_cpy = *stack;
	next_cpy = (*stack)->next;
	if (!(last == next_cpy))
	{
		stack_cpy->next = next_cpy->next;
		next_cpy->next->prev = stack_cpy;
		next_cpy->next = stack_cpy;
		stack_cpy->prev = next_cpy;
		last->next = next_cpy;
		next_cpy->prev = last;
	}
	*stack = next_cpy;
}

void	push(t_dclist **stack_a, t_dclist **stack_b)
{
	t_dclist	*tmp_next;
	t_dclist	*tmp_prev;
	t_dclist	*tmp;

	tmp = *stack_a;
	if ((*stack_a)->next != tmp)
	{
		tmp_next = (*stack_a)->next;
		tmp_prev = (*stack_a)->prev;
		tmp->next = tmp;
		tmp->prev = tmp;
		ft_lstadd_front(stack_b, *stack_a);
		tmp_next->prev = tmp_prev;
		tmp_prev->next = tmp_next;
		*stack_a = tmp_next;
	}
	else
	{
		(*stack_a)->next = (*stack_b);
		(*stack_a)->prev = ft_lstlast(*stack_b);
		ft_lstlast(*stack_b)->next = (*stack_a);
		(*stack_b)->prev = (*stack_a);
		(*stack_b) = tmp;
		(*stack_a) = NULL;
	}
}

void	rotate(t_dclist **stack)
{
	*stack = (*stack)->next;
}

void	reverse_rotate(t_dclist **stack)
{
	*stack = (*stack)->prev;
}

void	command(int command, t_dclist **stack_a,
			 t_dclist **stack_b, t_tdata *data)
{
	void		(*f[NUM])(t_dclist **stack);
	t_dclist	**stack;

	f[SA] = swap;
	f[SB] = swap;
	f[RA] = rotate;
	f[RB] = rotate;
	f[RRA] = reverse_rotate;
	f[RRB] = reverse_rotate;
	if (command == SA || command == RA || command == RRA)
		stack = stack_a;
	else if (command == SB || command == RB || command == RRB)
		stack = stack_b;
	if (!(command == PA || command == PB))
		f[command](stack);
	if (command == PA)
		push(stack_b, stack_a);
	if (command == PB)
		push(stack_a, stack_b);
	if (!ft_cmd_lstadd_back(command, data))
	{
		stackclear(stack_a, stack_b, data);
		cmd_clear(data->cmd_list);
		put_error();
	}
}
