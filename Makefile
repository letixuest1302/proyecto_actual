NAME		= push_swap
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
SRCS		= main.c error.c parse.c parse_args.c swap.c push.c rotate.c \
			reverse_rotate.c sort_utils.c sort_small.c push_swap.c \
			split.c split_utils.c
OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h split.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
