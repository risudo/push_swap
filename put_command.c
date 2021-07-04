#include "push_swap.h"

void	put_command(int command)
{
	if (command == SA)
		write(1, "sa\n", 3);
	if (command == SB)
		write(1, "sb\n", 3);
	if (command == SS)
		write(1, "ss\n", 3);
	if (command == PA)
		write(1, "pa\n", 3);
	if (command == PB)
		write(1, "pb\n", 3);
	if (command == RA)
		write(1, "ra\n", 3);
	if (command == RB)
		write(1, "rb\n", 3);
	if (command == RR)
		write(1, "rr\n", 3);
	if (command == RRA)
		write(1, "rra\n", 4);
	if (command == RRB)
		write(1, "rrb\n", 4);
	if (command == RRR)
		write(1, "rrr\n", 4);
}

void	put_cmd_list(t_tdata *data)
{
	t_list	*cmdlist;

	if (!data->cmd_list)
		return ;
	cmdlist = data->cmd_list;
	while (cmdlist->next != NULL)
	{
		put_command(cmdlist->cmd);
		cmdlist = cmdlist->next;
	}
	put_command(cmdlist->cmd);
}
