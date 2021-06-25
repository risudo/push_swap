#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# define FORMER 0
# define LATTER 1
# define SORTED -1

typedef struct s_dclist
{
	int				value;
	int				status;
	int				c_num;
	struct s_dclist	*prev;
	struct s_dclist	*next;
}	t_dclist;

typedef struct s_data
{
	int	max;
	int	min;
	int	len;
	int	min_place;
	int	sorted_len;
}	t_data;

typedef struct s_tdata
{
	t_data	*data_a;
	t_data	*data_b;
}	t_tdata;

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
void		push_swap(t_dclist **stack_a, t_dclist **stack_b, t_tdata *data);
void		put_error(void);
void		ft_lstadd_front(t_dclist **list, t_dclist *new);

// ft_atoi.c
int			*ft_atoi(const char *str);
int			error_check(long num, const char *str, int negative, int i);
bool		ft_isdigit(int c);

// push_data.c
void		push_data(t_dclist **stack, t_data *data);
void		update_value(t_dclist **stack, t_data *data, int cnt);
void		push_both_data(t_dclist **stack_a, t_dclist **stack_b, t_tdata *data);

// init_stack.c
void		init_stack_a(t_dclist **stack_a, t_data *data_a,
				 int argc, char **argv);
t_dclist	*ft_lstnew(int value);
t_dclist	*ft_lstlast(t_dclist *list);
void		ft_lstadd_back(t_dclist **list, t_dclist *new);
void		numbering_list(t_dclist **stack_a, t_data *data_a);


// command.c
void		command(int command, t_dclist **stack_a, t_dclist **stack_b);
void		reverse_rotate(t_dclist **stack);
void		swap(t_dclist **stack);
void		push(t_dclist **stack_a, t_dclist **stack_b);
void		rotate(t_dclist **stack);
void		reverse_rotate(t_dclist **stack);

// sort_three_five.c
void		sort_three_arg(t_dclist **stack_a,
				t_dclist **stack_b, t_data *data_a);
void		recursive_pb(t_dclist **stack_a, t_dclist **stack_b, t_data *data_a);
void		sort_five_arg(t_dclist **stack_a, t_dclist **stack_b, t_data *data_a);

// sort_utils.c
bool		is_sorted(t_dclist **stack_a, t_dclist **stack_b, t_data *data_a);
bool		is_stack(t_dclist **stack);
bool		bis_sorted(t_dclist **stack_b, t_data *data_b);

// split_stack.c
void		split_stack(t_dclist **stack_a, t_dclist **stack_b, t_tdata *data);
void		sortb_less_five(t_dclist **stack_a, t_dclist **stack_b, t_data *data_b);
void		sortb_five(t_dclist **stack_a, t_dclist **stack_b, t_data *data_b);
void		sortb_three(t_dclist **stack_a, t_dclist **stack_b, t_data *data_b);

// quick_sort.c
void		quick_sort(t_dclist **stack_a, t_dclist **stack_b, t_tdata *data);
void		pa_ra_sortedb(t_dclist **stack_a, t_dclist **stack_b);
void		sort_11arg(t_dclist **stack_a, t_dclist **stack_b, t_tdata *data);
int			get_pivot(t_dclist **stack, t_data *data);
void	pb_less_pivot(t_dclist **stack_a, t_dclist **stack_b, t_tdata *data);
void	pa_less_pivot(t_dclist **stack_a, t_dclist **stack_b, t_data *data_b);
// sort_ascending
void		sortb_ascending(t_dclist **stack_a, t_dclist **stack_b, t_data *data_b);
void		sortb_ascending_three(t_dclist **stack_a, t_dclist **stack_b, t_data *data_b);

// debug.c
void		put_stack(t_dclist *stack_a, t_dclist *stack_b);
void		put_data(t_data *data);

#endif