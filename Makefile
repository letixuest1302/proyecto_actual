NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = moves/Push.c moves/ReverseRotate.c moves/Rotate.c moves/swap.c parser/bench_utils.c \
		parser/error.c parser/is_sorted.c parser/parse_args.c parser/parse.c sort_algorithms/small_sort.c\
		sort_algorithms/adaptative_sort.c sort_algorithms/complex_sort.c sort_algorithms/medium_sort.c \
		sort_algorithms/simple_sort.c sort_algorithms/sort_utils.c split/split_utils.c split/split.c main_utils.c main.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re