#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_dclist
{
	int				value;
	struct s_dclist	*prev;
	struct s_dclist	*next;
}	t_dclist;

typedef struct s_data
{
	int	max;
	int	min;
	int	len;
	int	min_place;
	int	average;
	int	sorted_len;
}	t_data;

enum	e_cmd
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	NUM
};

int			*ft_atoi(const char *str);
void		put_stack(t_dclist *stack_a, t_dclist *stack_b);
void		put_error(void);
void		make_stack_a(t_dclist **stack_a, t_data *data_a,
				 int argc, char **argv);
t_dclist	*ft_lstlast(t_dclist *list);
t_dclist	*ft_lstnew(int value);
void		ft_lstadd_back(t_dclist **list, t_dclist *new);
void		ft_lstadd_front(t_dclist **list, t_dclist *new);
void		reverse_rotate(t_dclist **stack);
void		command(int command, t_dclist **stack_a, t_dclist **stack_b);
void		push_data(t_dclist **stack, t_data *data);

#endif