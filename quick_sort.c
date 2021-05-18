#include "push_swap.h"

int	is_sorted(t_list **stack_a, t_list **stack_b, t_deta *deta_a)
{
	int	tmp;
	int	i;

	i = -1;
	tmp = (*stack_a)->value;
	while (++i < deta_a->len)
	{
		if (tmp > (*stack_a)->value)
			deta_a->sorted_len = 0;
		tmp = (*stack_a)->value;
		(*stack_a) = (*stack_a)->next;
		deta_a->sorted_len++;
		put_stack(*stack_a, *stack_b);
	}
	if (deta_a->sorted_len == deta_a->len)
		return (1);
	else
		return (0);
}

void	quick_sort_pa(t_list **stack_a, t_list **stack_b, t_deta *deta_b)
{
	t_list	*p;
	int		i;
	int		j;

	j = 0;
	i = 0;
	p = (*stack_b);
	//while (j < len)
	//{
	//	
	//}
	while ((*stack_b)->next != p)
	{
		if ((*stack_b)->value <= deta_b->average)
		{
			command(PA, stack_a, stack_b);
			p = (*stack_b);
			i++;
		}
		else
			command(RB, stack_a, stack_b);
	}
	if ((*stack_b)->value <= deta_b->average)
	{
		command(PA, stack_a, stack_b);
		i++;
	}
	if (i < 7)
	{
		deta_b->len = i;
		push_swap(stack_a, stack_b, deta_b);
	}
	while (i)
	{
		command(RA, stack_a, stack_b);
		i--;
	}
}

void	quick_sort(t_list **stack_a, t_list **stack_b, t_deta *deta_a)
{
	t_list	*p;
	t_deta	deta_b;
	int		i;

	if (is_sorted(stack_a, stack_b, deta_a))
		return ;
	p = (*stack_a);
	while ((*stack_a)->next != p)
	{
		if ((*stack_a)->value < deta_a->average)
		{
			command(PB, stack_a, stack_b);
			p = (*stack_a);
		}
		else
			command(RA, stack_a, stack_b);
	}
	if ((*stack_a)->value < deta_a->average)
	{
		command(PB, stack_a, stack_b);
	}
	while (is_stack(stack_b))
	{
		push_deta(stack_b, &deta_b);
		quick_sort_pa(stack_a, stack_b, &deta_b);
	}
	put_stack(*stack_a, *stack_b);
	push_deta(stack_a, deta_a);
	// quick_sort(stack_a, stack_b, deta_a);
	// push_deta(stack_b, &deta_b);
	// quick_sort_pa(stack_a, stack_b, &deta_b);

}

/*
?	リストをwhileで回す時、長さを決めてその長さ分回すようにする
?	is_sortedで末尾にソート済みが何個あるか数える
?	whileを回すときはlen - sorted_lenの数だけ回すようにする
?
?	1	PAした時にそれが６個以内だった場合ソートして末尾に移動
?	2	6個より多かった場合、大小で分割してPB
*	Aの末尾は必ずソート済みのものを置くようにする
	
*/
