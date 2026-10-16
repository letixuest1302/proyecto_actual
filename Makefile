# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lesainz <lesainz@student.42madrid.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/14 12:08:49 by lesainz           #+#    #+#              #
#    Updated: 2026/10/16 11:29:19 by lesainz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
REM = rm -vf

SRCS = ft_hexadez.c \
	ft_printf.c \
	ft_putnbr_fd.c \
	ft_strlen.c \
	ft_isalpha.c \
	ft_putstr_fd.c \
	ft_tolower.c \
	ft_loweryuppercase.c \
	ft_putchar_fd.c \
	ft_putthing.c \
	ft_toupper.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(REM) $(OBJS)

fclean: clean
	$(REM) $(NAME)

re: fclean all

.PHONY: all clean fclean re


