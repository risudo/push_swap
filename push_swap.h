#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <libc.h>

typedef struct s_list
{
	long			value;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

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

void	swap(t_list **stac_a);
void	push(t_list **stac_a, t_list **stac_b);
t_list	*ft_lstlast(t_list *list);
void	reverse_rotate(t_list **stac);
void	ft_lstadd_front(t_list **list, t_list *new);
void	rotate(t_list **stac);
void	command(int command, t_list **stac_a, t_list **stac_b);
#endif
