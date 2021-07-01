#include "push_swap.h"

void	optimize_cmdlist(t_tdata *data)
{
	// omit_pa_pb(data->cmd_list);
	find_omit_rotate(data->cmd_list);
	find_omit(data->cmd_list);//ra->rra
	find_sa_ra_pb(data->cmd_list);
}

void	find_sa_ra_pb(t_list *cmd_list)
{
	if (!(cmd_list && cmd_list->next && cmd_list->next->next))
		return ;
	while (cmd_list->next->next != NULL)
	{
		if (cmd_list->cmd == SA && cmd_list->next->cmd == RA
			&& cmd_list->next->next->cmd == PB)
		{
			cmd_list->cmd = PB;
			cmd_list->next->next->cmd = -1;
		}
		cmd_list = cmd_list->next;
	}
}

void	find_omit_rotate(t_list *cmd_list)
{
	t_list	*p;

	while (cmd_list->next != NULL)
	{
		p = is_omit_2cmd(cmd_list->cmd, cmd_list);
		if (p)
		{
			cmd_list->cmd = -1;
			p->cmd = -1;
		}
		cmd_list = cmd_list->next;
	}
}

t_list	*is_omit_2cmd(int cmd1, t_list *cmd_list)
{
	int		cmd2;
	t_list	*p;

	if (cmd_list->prev == NULL)
		return (NULL);
	p = cmd_list->prev;
	while (p->cmd == -1)
	{
		p = p->prev;
	}
	cmd2 = p->cmd;
	if ((cmd1 == RA && cmd2 == RRA) || (cmd1 == RB && cmd2 == RRB)
		|| (cmd1 == RRA && cmd2 == RA) || (cmd1 == RRB && cmd2 == RB)
		|| (cmd1 == PA && cmd2 == PB) || (cmd1 == PB && cmd2 == PA))
		return (p);
	else
		return (NULL);
}

void	find_omit(t_list *cmd_list)
{
	t_list	*start;

	start = cmd_list;
	while (cmd_list->next != NULL)
	{
		if (is_use_rr(cmd_list->cmd, cmd_list->next->cmd))
		{
			cmd_list->cmd = RR;
			cmd_list->next->cmd = -1;
		}
		else
			cmd_list = cmd_list->next;
	}
}

// void	use_rr(t_list *cmd_list)
// {
// 	cmd_list->cmd = RR;
// 	cmd_list->next->cmd = -1;
// }

bool	is_use_rr(int cmd1, int cmd2)
{
	if ((cmd1 == RA && cmd2 == RB) || (cmd1 == RB && cmd2 == RA))
		return (true);
	else
		return (false);
}
