NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a

HEADER = push_swap.h

SRCS = error/error_check.c error/error.c main/main.c moves/push.c moves/rev_rotate.c moves/rotate.c moves/swap.c sorts/sort_3.c sorts/calculations.c sorts/sort.c utils/util_1.c utils/util_2.c

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBFT)

debug:
	$(CC) $(SRCS) -g -o ../debugger/a.out

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
