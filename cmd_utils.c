#include "push_swap.h"

void	ra(t_dclist **stack_a, t_dclist **stack_b, t_tdata *data)
{
	(*stack_a)->status = SORTED;
	command(RA, stack_a, stack_b, data);
}

void	pa_ra(t_dclist **stack_a, t_dclist **stack_b, t_tdata *data)
{
	(*stack_b)->status = SORTED;
	command(PA, stack_a, stack_b, data);
	command(RA, stack_a, stack_b, data);
}

void	sa_ra(t_dclist **stack_a, t_dclist **stack_b, t_tdata *data)
{
	command(SA, stack_a, stack_b, data);
	(*stack_a)->status = SORTED;
	command(RA, stack_a, stack_b, data);
}

void	sb_pa_ra(t_dclist **stack_a, t_dclist **stack_b, t_tdata *data)
{
	command(SB, stack_a, stack_b, data);
	(*stack_b)->status = SORTED;
	command(PA, stack_a, stack_b, data);
	command(RA, stack_a, stack_b, data);
}

void	rrb_pa_ra(t_dclist **stack_a, t_dclist **stack_b, t_tdata *data)
{
	command(RRB, stack_a, stack_b, data);
	command(PA, stack_a, stack_b, data);
	(*stack_a)->status = SORTED;
	command(RA, stack_a, stack_b, data);
}


