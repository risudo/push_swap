#include "push_swap.h"
//*:	先頭の2つを入れ替える
void	swap(t_list **stac)
{
	t_list	*stac_cpy;
	t_list	*next_cpy;
	t_list	*last;

	last = ft_lstlast(*stac);
	stac_cpy = *stac;
	next_cpy = (*stac)->next;
	stac_cpy->next = next_cpy->next;
	next_cpy->next->prev = stac_cpy;
	next_cpy->next = stac_cpy;
	stac_cpy->prev = next_cpy;
	last->next = next_cpy;
	next_cpy->prev = last;
	*stac = next_cpy;
}
//*:	第一引数の先頭を第二引数の先頭に移動する
//*:	stac_aを全部stac_bに写そうとするとバグる
void	push(t_list **stac_a, t_list **stac_b)
{
	t_list	*tmp_next;
	t_list	*tmp_prev;
	t_list	*tmp;

	tmp = *stac_a;
	if ((*stac_a)->next != tmp)
	{
		tmp_next = (*stac_a)->next;
		tmp_prev = (*stac_a)->prev;
		tmp->next = tmp;
		tmp->prev = tmp;
		ft_lstadd_front(stac_b, *stac_a);
		tmp_next->prev = tmp_prev;
		tmp_prev->next = tmp_next;
		*stac_a = tmp_next;
	}
	else
	{
		(*stac_a)->next = (*stac_b);
		(*stac_a)->prev = ft_lstlast(*stac_b);
		ft_lstlast(*stac_b)->next = (*stac_a);
		(*stac_b)->prev = (*stac_a);
		(*stac_b) = tmp;
		(*stac_a) = NULL;
	}
}

void	rotate(t_list **stac)
{
	*stac = (*stac)->next;
}

void	reverse_rotate(t_list **stac)
{
	*stac = (*stac)->prev;
}

void	command(int command, t_list **stac_a, t_list **stac_b)
{
	void	(*f[NUM])(t_list **stac);
	t_list	**stac;

	f[SA] = swap;
	f[SB] = swap;
	f[RA] = rotate;
	f[RB] = rotate;
	f[RRA] = reverse_rotate;
	f[RRB] = reverse_rotate;
	if (command == SA || command == RA || command == RRA)
		stac = stac_a;
	else if (command == SB || command == RB || command == RRB)
		stac = stac_b;
	if (!(command == PA || command == PB))
		f[command](stac);
	if (command == PA)
		push(stac_a, stac_b);
	if (command == PB)
		push(stac_b, stac_a);
}