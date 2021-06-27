#include "push_swap.h"

void	ft_cmd_lstadd_back(int command, t_tdata *data)
{
	t_list	*new;
	t_list	*last;

	new = ft_cmd_lstnew(command);
	if (!(data->cmd_list))
	{
		data->cmd_list = new;
		return ;
	}
	last = ft_cmd_lstlast(data->cmd_list);
	last->next = new;
	new->prev = last;
}

t_list	*ft_cmd_lstlast(t_list *list)
{
	while (list->next != NULL)
		list = list->next;
	return (list);
}

t_list	*ft_cmd_lstnew(int command)
{
	t_list *new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return(NULL); //
	new->cmd = command;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}