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
		// put_stack(*stack_a, *stack_b);
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
		printf("---quick_sort_pa---\n");
	j = 0;
	i = 0;
	p = (*stack_b);
		printf("len: %d\n", deta_b->len);
	//６個以下だったらソートしてPA->RA
	//６個以上だったら６個以下になるまで半分以上をPA

	if (deta_b->len < 7)
	{
		put_stack(*stack_a, *stack_b);
		sort_stack_b(stack_a, stack_b, deta_b);
		while (is_stack(stack_b))
		{
			command(PA, stack_a, stack_b);
			command(RA, stack_a, stack_b);
		}
	}
	else
	{
		//６個以下になるまで平均より大きいやつをPA
		while (i < deta_b->len)
		{
			if ((*stack_b)->value > deta_b->average)
				command(PA, stack_a, stack_b);
			else
				command(RB, stack_a, stack_b);
			i++;
		}
		push_deta(stack_b, deta_b);
		quick_sort_pa(stack_a, stack_b, deta_b);
	}
}

void	quick_sort(t_list **stack_a, t_list **stack_b, t_deta *deta_a)
{
	t_list	*p;
	t_deta	deta_b;
	int		i;

	printf("---quick_sort---\n");
	if (is_sorted(stack_a, stack_b, deta_a))
		return ;
	i = 0;
		printf("len: %d\nsorted_len: %d\n", deta_a->len, deta_a->sorted_len);
	//平均以下をPBする
	while (i < deta_a->len)
	{
		if ((*stack_a)->value < deta_a->average)
		{
			command(PB, stack_a, stack_b);
		}
		else
			command(RA, stack_a, stack_b);
		put_stack(*stack_a, *stack_b);
		i++;
	}
	//スタックBの操作に移る
	push_deta(stack_b, &deta_b);
	quick_sort_pa(stack_a, stack_b, &deta_b);
	if (is_sorted(stack_a, stack_b, deta_a))
		return ;
	//未ソートが6個以下だったらPBしてソート
	put_stack(*stack_a, *stack_b);
	// if (deta_a->len - deta_a->sorted_len < 7)
	// {
		i = 0;
		printf("sorted_len: %d\n", deta_a->sorted_len);
		while (i < deta_a->len - deta_a->sorted_len)
		{
			command(PB, stack_a, stack_b);
			i++;
		}
		push_deta(stack_b, &deta_b);
		quick_sort_pa(stack_a, stack_b, &deta_b);
	// }
	put_stack(*stack_a, *stack_b);
}

/*
?	リストをwhileで回す時、長さを決めてその長さ分回すようにする
?	is_sortedで末尾にソート済みが何個あるか数える
?	whileを回すときはlen - sorted_lenの数だけ回すようにする
?	PBしたときに6以下だったらソート->PA->RA
?	6個より多かった場合、6個以下になるまで大きい方を半分PA
*	Aの末尾は必ずソート済みのものを置くようにする

*/
