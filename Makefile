NAME = push_swap.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = moves/Push.c moves/ReverseRotate.c moves/Rotate.c moves/swap.c \
	sort_algorithms/adaptative_sort.c sort_algorithms/complex_sort.c sort_algorithms/medium_sort.c sort_algorithms/simple_sort.c \
	split/split_utils.c split/split.c error.c is_sorted.c parse_args.c parse.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re