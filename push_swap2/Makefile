NAME		= push_swap
NAME_BONUS	= checker

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
LIBFT		= ./libft/libft.a

HEADER		= push_swap.h

SRCS		=	error/error_check.c\
				main/main.c\
				moves/push.c moves/rev_rotate.c moves/rotate.c moves/swap.c\
				sorts/init.c sorts/move_cost.c sorts/move_maker.c sorts/sort.c\
				utils/util_1.c utils/util_2.c

SRCS_BONUS	=	bonus/checker.c\
				bonus/push_checker.c bonus/rotate_checker.c bonus/rev_rotate_checker.c bonus/swap_checker.c\
				error/error_check.c\
				moves/push.c moves/rev_rotate.c moves/rotate.c moves/swap.c\
				sorts/init.c sorts/move_cost.c sorts/move_maker.c sorts/sort.c\
				utils/util_1.c utils/util_2.c

OBJS		= $(SRCS:%.c=%.o)

OBJS_BONUS	= $(SRCS_BONUS:%.c=%.o)

all:		$(NAME)

$(LIBFT):
				$(MAKE) -C ./libft

$(NAME):		$(LIBFT) $(OBJS)
				$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBFT)

bonus:			$(NAME_BONUS)

$(NAME_BONUS):	$(LIBFT) $(OBJS_BONUS)
				$(CC) $(CFLAGS) -o $@ $(OBJS_BONUS) $(LIBFT)

debug:
	$(CC) $(SRCS) $(LIBFT) -g -o ../debugger/a.out

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re
