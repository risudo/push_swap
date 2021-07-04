NAME	=	push_swap

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

SRCS	=	main.c \
			ft_atoi.c \
			init_stack.c \
			sort_utils.c \
			split_stack.c \
			push_data.c \
			quick_sort.c \
			sort_less_five.c \
			command.c \
			put_command.c \
			cmd_list.c \
			optimize_cmdlist.c \
			list_clear.c \
			cmd_utils.c \
			cmd_utils2.c \
			duplicates_error.c \
#			debug.c

OBJS	=	${SRCS:.c=.o}

HEADER	=	push_swap.h

%.o		:	%.c
			${CC} ${CFLAGS} -c $< -o $@

$(NAME)	:	$(OBJS)
			${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all		:	${NAME}

clean	:
			rm -rf ${OBJS}

fclean	:	clean
			rm -rf ${NAME}

re		:	fclean all

.PHONY	:	all clean fclean re