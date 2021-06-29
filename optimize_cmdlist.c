#include "push_swap.h"

void	optimize_cmdlist(t_tdata *data)
{
	// omit_pa_pb(data->cmd_list);
	find_omit(data->cmd_list);//ra->rra
}

// void	use_rr_rrr(t_list *cmd_list)
// {

// }

void	find_omit(t_list *cmd_list)
{
	t_list	*start;

	start = cmd_list;
	while (cmd_list->next != NULL)
	{
		// put_command(cmd_list->cmd);
		// printf("%p\n", cmd_list);
		// if (is_omit_rotate(cmd_list->cmd, cmd_list->next->cmd))
		// {
		// 	omit_rotate(cmd_list);
		// }
		if (is_use_rr(cmd_list->cmd, cmd_list->next->cmd))
		{
			use_rr(cmd_list);
		}
		else
			cmd_list = cmd_list->next;
	}
	cmd_list = start;
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

void	omit_rotate(t_list *cmd_list)
{
	t_list *tmp_free;
//cmd == rb
//next->cmd == rrb
	write(1, "\ndebug\n", 7);
	put_command(cmd_list->prev->cmd);
	put_command(cmd_list->cmd);
	put_command(cmd_list->next->cmd);
	put_command(cmd_list->next->next->next->cmd);

	tmp_free = cmd_list;
	cmd_list->prev->next = cmd_list->next->next;
	cmd_list->next->next->prev = cmd_list->prev;
	cmd_list = cmd_list->prev;
	write(1, "debug\n\n", 7);
	put_command(cmd_list->cmd);
	put_command(cmd_list->next->cmd);
	free(tmp_free);
	free(tmp_free->next);
	put_command(cmd_list->cmd);
	// put_command(cmd_list->next->cmd);
	// exit(0);
}

bool	is_omit_rotate(int cmd1, int cmd2)
{
	if ((cmd1 == RA && cmd2 == RRA) || (cmd1 == RB && cmd2 == RRB)
		|| (cmd1 == RRA && cmd2 == RA) || (cmd1 == RRB && cmd2 == RB)
		|| (cmd1 == PA && cmd2 == PB) || (cmd1 == PB && cmd2 == PA))
		return (true);
	else
		return (false);
}
