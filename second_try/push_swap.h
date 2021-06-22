#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define FORMER 0
# define LATTER 1
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>

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
// mainc.c
void		push_swap(t_dclist **stack_a, t_dclist **stack_b,
				t_data *data_a, t_data *data_b);
void		put_error(void);
void		ft_lstadd_front(t_dclist **list, t_dclist *new);

// ft_atoi.c
int			*ft_atoi(const char *str);
int			error_check(long num, const char *str, int negative, int i);
bool		ft_isdigit(int c);

// push_data.c
void		push_data(t_dclist **stack, t_data *data);
void		update_value(t_dclist **stack, t_data *data, int cnt);

// init_stack.c
void		make_stack_a(t_dclist **stack_a, t_data *data_a,
				 int argc, char **argv);
t_dclist	*ft_lstnew(int value);
t_dclist	*ft_lstlast(t_dclist *list);
void		ft_lstadd_back(t_dclist **list, t_dclist *new);

// command.c
void		command(int command, t_dclist **stack_a, t_dclist **stack_b);
void		reverse_rotate(t_dclist **stack);

// sort_three_five.c
void		sort_three_arg(t_dclist **stack_a,
				t_dclist **stack_b, t_data *data_a);
void	recursive_pb(t_dclist **stack_a, t_dclist **stack_b, t_data *data_a);
void	sort_five_arg(t_dclist **stack_a, t_dclist **stack_b, t_data *data_a);

// sort_utils.c
bool		is_sorted(t_dclist **stack_a, t_dclist **stack_b, t_data *data_a);
bool		is_stack(t_dclist **stack);

// debug.c
void		put_stack(t_dclist *stack_a, t_dclist *stack_b);
void		put_data(t_data *data);

#endif