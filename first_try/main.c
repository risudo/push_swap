#include "push_swap.h"

long	ft_atol(char *str)
{
	int		i;
	long	ret;

	i = 0;
	ret = 0;
	while (str[i])
	{
		ret *= 10;
		ret += str[i] + '0';
	}
	return (ret);
}

int	is_stack(t_list **stack)
{
	if (*stack)
		return (1);
	return (0);
}

void	push_sorted_deta(t_list **stack, t_deta *deta)
{
	int		i;
	t_list	*p;

	p = (*stack);
	i = 0;
	deta->max = (*stack)->value;
	deta->min = (*stack)->value;
	while (i < deta->sorted_len)
	{
		update_value(stack, deta, 0);
		(*stack) = (*stack)->next;
		i++;
	}
	deta->average = (deta->min + deta->max) / 2;
}

void	update_value(t_list **stack, t_deta *deta, int cnt)
{
	if (deta->min > (*stack)->value)
	{
		deta->min_place = cnt + 1;
		deta->min = (*stack)->value;
	}
	if (deta->max < (*stack)->value)
		deta->max = (*stack)->value;
}

void	push_deta(t_list **stack, t_deta *deta)
{
	t_list	*p;
	int		cnt;

	cnt = 0;
	deta->sorted_len = 0;
	p = (*stack);
	deta->max = (*stack)->value;
	deta->min = (*stack)->value;
	while ((*stack)->next != p)
	{
		update_value(stack, deta, cnt);
		cnt++;
		(*stack) = (*stack)->next;
	}
	update_value(stack, deta, cnt);
	deta->len = cnt + 1;
	if (deta->len / 2 >= deta->min_place || (deta->len == 5 && deta->min_place == 3))
		deta->min_place = FORMER;
	else
		deta->min_place = LATTER;
	deta->average = (deta->min + deta->max) / 2;
	(*stack) = p;
}

t_list	*ft_lstnew(long value)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->value = value;
	new->next = new;
	new->prev = new;
	return (new);
}

t_list	*ft_lstlast(t_list *list)
{
	t_list *p;

	p = list;
	while (list->next != p)
	{
		list = list->next;
	}
	return (list);
}

void	ft_lstadd_back(t_list **list, t_list *new)
{
	t_list	*p;

	if (!*list)
	{
		*list = new;
		return ;
	}
	p = ft_lstlast(*list);
	(*list)->prev = new;
	p->next = new;
	new->prev = p;
	new->next = (*list);
}

void	ft_lstadd_front(t_list **list, t_list *new)
{
	t_list	*p;

	if (!*list)
	{
		*list = new;
		return ;
	}
	p = ft_lstlast(*list);
	new->next = *list;
	(*list)->prev = new;
	p->next = new;
	new->prev = p;
	*list = new;
}

void	make_stack_a(t_list **stack, int argc, char **argv, t_deta *deta)
{
	int		i;
	t_list	*tmp;

	i = 1;
	while (i < argc)
	{
		tmp = ft_lstnew(atol(argv[i]));
		if (!tmp)
		{
			return ;
		}
		ft_lstadd_back(stack, tmp);
		i++;
	}
	push_deta(stack, deta);
}

void	put_stack(t_list *stack_a, t_list *stack_b)
{
	t_list	*p_a;
	t_list	*p_b;
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
		printf("i: %d\tvalue: %ld\n", i, stack_a->value);
		stack_a = stack_a->next;
		i++;
	}
	printf("i: %d\tvalue: %ld\n", i, stack_a->value);
	printf("\n");
	// while (stack_a != p_a)
	// {
	// 	printf("i: %d\tvalue: %ld\n", i, stack_a->value);
	// 	stack_a = stack_a->prev;
	// 	i--;
	// }
	// printf("i: %d\tvalue: %ld\n", i, stack_a->value);
	// printf("\n");
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
		printf("i: %d\tvalue: %ld\n", i, stack_b->value);
		stack_b = stack_b->next;
		i++;
	}
	printf("i: %d\tvalue: %ld\n", i, stack_b->value);
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
/*
?:	被りチェックはソートしてからの方がいいかな
*/
int	error_check(int argc, char **argv)
{
	int	i;
	int	j;
	int	err;

	err = 0;
	i = 1;
	if (argc == 1)
		err = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				err = 1;
			j++;
		}
		i++;
	}
	if (err)
	{
		write(2, "ERROR\n", 6);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_deta	deta;
	int		i;

	if (error_check(argc, argv))
		return (0);
	make_stack_a(&stack_a, argc, argv, &deta);
	push_swap(&stack_a, &stack_b, &deta);
	put_stack(stack_a, stack_b);


	return (0);
}