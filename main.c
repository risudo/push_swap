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

// void	ft_lstadd_back(t_list **list, t_list *new)
// {
// 	t_list	*p;

// 	if (!*list)
// 	{
// 		*list = new;
// 		return ;
// 	}
// 	p = ft_lstlast(*list);
// 	(*list)->prev = new;
// 	p->next = new;
// 	new->prev = p;
// 	new->next = (*list);
// }

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

void	make_stac_a(t_list **stac, int argc, char **argv)
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
		// ft_lstadd_back(stac, tmp);
		ft_lstadd_front(stac, tmp);
		i++;
	}
}

void	put_stac(t_list *stac_a, t_list *stac_b)
{
	t_list	*p_a;
	t_list	*p_b;
	int		i;

	i = 1;
	p_a = stac_a;
	p_b = stac_b;
	printf("---a---\n");
	if (!stac_a)
	{
		printf("(null)\n");
		goto STAC_B;
	}
	while (stac_a ->next != p_a)
	{
		printf("i: %d\tvalue: %ld\n", i, stac_a->value);
		stac_a = stac_a->next;
		i++;
	}
	printf("i: %d\tvalue: %ld\n", i, stac_a->value);
	printf("\n");
	while (stac_a != p_a)
	{
		printf("i: %d\tvalue: %ld\n", i, stac_a->value);
		stac_a = stac_a->prev;
		i--;
	}
	printf("i: %d\tvalue: %ld\n", i, stac_a->value);
	printf("\n");

STAC_B:
	printf("---b---\n");
	if (!stac_b)
	{
		printf("(null)\n");
		return ;
	}
	while (stac_b ->next != p_b)
	{
		printf("i: %d\tvalue: %ld\n", i, stac_b->value);
		stac_b = stac_b->next;
		i++;
	}
	printf("i: %d\tvalue: %ld\n", i, stac_b->value);
	printf("\n");
	while (stac_b != p_b)
	{
		printf("i: %d\tvalue: %ld\n", i, stac_b->value);
		stac_b = stac_b->prev;
		i--;
	}
	printf("i: %d\tvalue: %ld\n", i, stac_b->value);
	printf("\n");
}
/*
?:	被りチェックはソートしてからの方がいいかな
*/
int	error_check(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argc == 1)
		return (1);
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*stac_a;
	t_list	*stac_b;
	int		i;

	if (error_check(argc, argv))
		return (0);
	make_stac_a(&stac_a, argc, argv);
	put_stac(stac_a, stac_b);
	command(PA, &stac_a, &stac_b);
	put_stac(stac_a, stac_b);
	command(PA, &stac_a, &stac_b);
	put_stac(stac_a, stac_b);
	command(PA, &stac_a, &stac_b);
	put_stac(stac_a, stac_b);
	command(PA, &stac_a, &stac_b);
	put_stac(stac_a, stac_b);

	return (0);
}