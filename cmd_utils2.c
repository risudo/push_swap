#include "push_swap.h"

void	rrb_pa_ra(t_dclist **stack_a, t_dclist **stack_b, t_tdata *data)
{
	command(RRB, stack_a, stack_b, data);
	command(PA, stack_a, stack_b, data);
	(*stack_a)->status = SORTED;
	command(RA, stack_a, stack_b, data);
}

void	rrb_rrb_pa_ra(t_dclist **stack_a, t_dclist **stack_b, t_tdata *data)
{
	command(RRB, stack_a, stack_b, data);
	command(RRB, stack_a, stack_b, data);
	command(PA, stack_a, stack_b, data);
	(*stack_a)->status = SORTED;
	command(RA, stack_a, stack_b, data);
}

void	rb_sb_pa_ra(t_dclist **stack_a, t_dclist **stack_b, t_tdata *data)
{
	command(RB, stack_a, stack_b, data);
	command(SB, stack_a, stack_b, data);
	command(PA, stack_a, stack_b, data);
	(*stack_a)->status = SORTED;
	command(RA, stack_a, stack_b, data);
	command(RRB, stack_a, stack_b, data);
}

void	rrb_rrb_rrb_pa_ra(t_dclist **stack_a, t_dclist **stack_b, t_tdata *data)
{
	command(RRB, stack_a, stack_b, data);
	command(RRB, stack_a, stack_b, data);
	command(RRB, stack_a, stack_b, data);
	command(PA, stack_a, stack_b, data);
	(*stack_a)->status = SORTED;
	command(RA, stack_a, stack_b, data);
}
