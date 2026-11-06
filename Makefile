NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = Moves/Push.c Moves/reverseRotate.c Moves/rotate.c Moves/swap.c \
	Parser/bench_utils.c Parser/error.c Parser/is_sorted.c Parser/parse_args.c Parser/parse.c \
	Sort_algorithms/adaptative_sort.c Sort_algorithms/complex_sort.c Sort_algorithms/medium_sort.c Sort_algorithms/simple_sort.c Sort_algorithms/small_sort.c \
	Split/split_utils.c Split/split.c main_utils.c main.c Sort_algorithms/sort_utils.c

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