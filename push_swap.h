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
	int				order;
	struct s_dclist	*prev;
	struct s_dclist	*next;
}	t_dclist;

typedef struct s_list
{
	int				cmd;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

typedef struct s_data
{
	int	max;
	int	min;
	int	len;
	int	min_place;
	int	sorted_len;
	int	max_c_num;
	int	min_c_num;
	int	min_notsort;
}	t_data;

typedef struct s_tdata
{
	t_data	*data_a;
	t_data	*data_b;
	t_list	*cmd_list;
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
void		push_both_data(t_dclist **stack_a,
				t_dclist **stack_b, t_tdata *data);

// init_stack.c
bool		init_stack_a(t_dclist **stack_a, t_data *data_a,
				 int argc, char **argv);
t_dclist	*ft_lstnew(int value);
t_dclist	*ft_lstlast(t_dclist *list);
void		ft_lstadd_back(t_dclist **list, t_dclist *new);
void		numbering_list(t_dclist **stack_a, t_data *data_a);

// command.c
void		command(int command, t_dclist **stack_a,
				t_dclist **stack_b, t_tdata *data);
void		reverse_rotate(t_dclist **stack);
void		swap(t_dclist **stack);
void		push(t_dclist **stack_a, t_dclist **stack_b);
void		rotate(t_dclist **stack);
void		reverse_rotate(t_dclist **stack);

// put_command.c
void	put_command(int command);
void	put_cmd_list(t_tdata *data);


// cmd_utils.c
void		pa_ra(t_dclist **stack_a, t_dclist **stack_b, t_tdata *data);
void		sa_ra(t_dclist **stack_a, t_dclist **stack_b, t_tdata *data);
void		sb_pa_ra(t_dclist **stack_a, t_dclist **stack_b, t_tdata *data);
void		rrb_pa_ra(t_dclist **stack_a, t_dclist **stack_b, t_tdata *data);
void		rrb_rrb_pa_ra(t_dclist **stack_a,
				t_dclist **stack_b, t_tdata *data);
void		ra(t_dclist **stack_a, t_dclist **stack_b, t_tdata *data);
void		rb_sb_pa_ra(t_dclist **stack_a, t_dclist **stack_b, t_tdata *data);
void		rrb_rrb_rrb_pa_ra(t_dclist **stack_a,
				t_dclist **stack_b, t_tdata *data);

// cmd_list.c
bool		ft_cmd_lstadd_back(int command, t_tdata *data);
t_list		*ft_cmd_lstlast(t_list *list);
t_list		*ft_cmd_lstnew(int command);

// sort_three_five.c
void		sort_three_arg(t_dclist **stack_a,
				t_dclist **stack_b, t_tdata *data);
void		recursive_pb(t_dclist **stack_a, t_dclist **stack_b, t_tdata *data);
void		sort_five_arg(t_dclist **stack_a,
				 t_dclist **stack_b, t_tdata *data);

// sort_utils.c
bool		is_sorted(t_dclist **stack_a, t_dclist **stack_b, t_data *data_a);
bool		is_stack(t_dclist **stack);
bool		bis_sorted(t_dclist **stack_b, t_data *data_b);

// split_stack.c
void		split_stack(t_dclist **stack_a,
				t_dclist **stack_b, t_tdata *data);
void		sortb_less_five(t_dclist **stack_a,
				t_dclist **stack_b, t_tdata *data);

// quick_sort.c
void		quick_sort(t_dclist **stack_a,
				t_dclist **stack_b, t_tdata *data);
int			get_pivot(t_dclist **stack, t_data *data);
bool		pa_more_pivot(t_dclist **stack_a,
				t_dclist **stack_b, t_tdata *data);
void		pb_same_status(t_dclist **stack_a,
				t_dclist **stack_b, t_tdata *data);
bool		push_min_ifpossible(t_dclist **stack_a,
				t_dclist **stack_b, t_tdata *data);
bool		is_large_num(t_dclist **stack_b, t_data *data_b, int pivot);

// optimize_cmdlist.c
void		optimize_cmdlist(t_tdata *data);
void		find_rr(t_list *cmd_list);
t_list		*is_omit_2cmd(int cmd1, t_list *cmd_list);
void		omit_2cmd(t_list *cmd_list);
void		use_rr(t_list *cmd_list);
bool		is_use_rr(int cmd1, int cmd2);
void		find_omit_2cmd(t_list *cmd_list);
void		find_sa_ra_pb(t_list *cmd_list);

// list_utils.c
void		stackclear(t_dclist **stack_a,
				t_dclist **stack_b, t_tdata *data);
void		cmd_clear(t_list *cmd_list);
void		duplicates_error(t_dclist **stack_a, t_data *data_a);

// debug.c
void		put_stack(t_dclist *stack_a, t_dclist *stack_b);
void		put_data(t_data *data);
void		put_cmd_list(t_tdata *data);
void		put_command(int command);

#endif