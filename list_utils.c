#include "push_swap.h"

void	ft_stackclear(t_dclist **stack_a, t_dclist **stack_b, t_tdata *data)
{
	t_dclist	*tmp;
	int	i;

	i = 0;
	while (i < data->data_a->len)
	{
		tmp = *stack_a;
		(*stack_a) = (*stack_a)->next;
		free(tmp);
		i++;
	}
	(void)stack_b;
}

void	cmd_clear(t_list *cmd_list)
{
	t_list	*tmp;

	while (cmd_list)
	{
		tmp = cmd_list->next;
		free(cmd_list);
		cmd_list = tmp;
	}
}