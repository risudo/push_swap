#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define FORMER 0
# define LATTER 1
# include <libc.h>

typedef struct s_list
{
	long			value;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

typedef struct	s_deta
{
	int	max;
	int	min;
	int	len;
	int	min_place;
	int	average;
	int	sorted_len;
}	t_deta;

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

void	swap(t_list **stack_a);
void	push(t_list **stack_a, t_list **stack_b);
t_list	*ft_lstlast(t_list *list);
void	reverse_rotate(t_list **stack);
void	ft_lstadd_front(t_list **list, t_list *new);
void	rotate(t_list **stack);
void	command(int command, t_list **stack_a, t_list **stack_b);
void	sort_three(t_list **stack_a, t_list **stack_b, t_deta *deta);
void	push_swap(t_list **stack_a, t_list **stack_b, t_deta *deta);
void	sort_three_node(t_list **stack_a, t_list **stack_b, t_deta *deta);
int		is_stack(t_list **stack);
void	recursive_pb(t_list **stack_a, t_list **stack_b, t_deta *deta);
void	push_deta(t_list **stack, t_deta *deta);
void	put_stack(t_list *stack_a, t_list *stack_b);
int		is_sorted(t_list **stack_a, t_list **stack_b, t_deta *deta_a);
void	quick_sort(t_list **stack_a, t_list **stack_b, t_deta *deta);
void	quick_sort_pa(t_list **stack_a, t_list **stack_b, t_deta *deta_b);
void	push_sorted_deta(t_list **stack, t_deta *deta);
void	update_value(t_list **stack, t_deta *deta, int cnt);
void	sort_stack_b(t_list **stack_a, t_list **stack_b, t_deta *deta);
void	sort_three_stack_b(t_list **stack_a, t_list **stack_b, t_deta *deta);
int	pa_small_node(t_list **stack_a, t_list **stack_b, t_deta *deta);
#endif
