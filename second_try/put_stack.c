#include "push_swap.h"

void	put_stack(t_dclist *stack_a, t_dclist *stack_b)
{
	t_dclist	*p_a;
	t_dclist	*p_b;
	int		i;

	i = 1;
	p_a = stack_a;
	p_b = stack_b;
	printf("---a---\n");
	if (!stack_a)
	{
		printf("(null)\n");
		goto STAC_B;
	}
	while (stack_a ->next != p_a)
	{
		printf("i: %d\tvalue: %d\n", i, stack_a->value);
		stack_a = stack_a->next;
		i++;
	}
	printf("i: %d\tvalue: %d\n", i, stack_a->value);
	// printf("\n");
	// while (stack_a != p_a)
	// {
	// 	printf("i: %d\tvalue: %d\n", i, stack_a->value);
	// 	stack_a = stack_a->prev;
	// 	i--;
	// }
	// printf("i: %d\tvalue: %d\n", i, stack_a->vlue);
	printf("\n");
	i = 1;

STAC_B:
	printf("---b---\n");
	if (!stack_b)
	{
		printf("(null)\n\n");
		return ;
	}
	while (stack_b ->next != p_b)
	{
		printf("i: %d\tvalue: %d\n", i, stack_b->value);
		stack_b = stack_b->next;
		i++;
	}
	printf("i: %d\tvalue: %d\n", i, stack_b->value);
	printf("\n");
	// while (stack_b != p_b)
	// {
	// 	printf("i: %d\tvalue: %ld\n", i, stack_b->value);
	// 	stack_b = stack_b->prev;
	// 	i--;
	// }
	// printf("i: %d\tvalue: %ld\n", i, stack_b->value);
	// printf("\n");
}