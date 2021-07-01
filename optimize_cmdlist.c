#include "push_swap.h"

void	optimize_cmdlist(t_tdata *data)
{
	// omit_pa_pb(data->cmd_list);
	find_omit_rotate(data->cmd_list);
	find_omit(data->cmd_list);//ra->rra
}

void	find_omit_rotate(t_list *cmd_list)
{
	while (cmd_list->next != NULL)
	{
		if (is_omit_2cmd(cmd_list->cmd, cmd_list->next->cmd))
		{
			omit_2cmd(cmd_list);
		}
		// else
			cmd_list = cmd_list->next;
	}
}

void	omit_2cmd(t_list *cmd_list)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = cmd_list;
	tmp2 = cmd_list->next;
	cmd_list->prev->next = cmd_list->next->next;
	cmd_list->next->next->prev = cmd_list->prev;
	cmd_list = cmd_list->prev;
	free(tmp1);
}

bool	is_omit_2cmd(int cmd1, int cmd2)
{
	if ((cmd1 == RA && cmd2 == RRA) || (cmd1 == RB && cmd2 == RRB)
		|| (cmd1 == RRA && cmd2 == RA) || (cmd1 == RRB && cmd2 == RB)
		|| (cmd1 == PA && cmd2 == PB) || (cmd1 == PB && cmd2 == PA))
		return (true);
	else
		return (false);
}

void	find_omit(t_list *cmd_list)
{
	t_list	*start;

	start = cmd_list;
	while (cmd_list->next != NULL)
	{
		if (is_use_rr(cmd_list->cmd, cmd_list->next->cmd))
		{
			use_rr(cmd_list);
		}
		else
			cmd_list = cmd_list->next;
	}
}

void	use_rr(t_list *cmd_list)
{
	t_list *p_free;

	p_free = cmd_list->next;
	cmd_list->cmd = RR;
	cmd_list->next = cmd_list->next->next;
	cmd_list->next->next->prev = cmd_list;
	free(p_free);
}

bool	is_use_rr(int cmd1, int cmd2)
{
	if ((cmd1 == RA && cmd2 == RB) || (cmd1 == RB && cmd2 == RA))
		return (true);
	else
		return (false);
}