# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_count_harvest_iterative.py                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lesainz <lesainz@student.42madrid.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/12 10:54:22 by lesainz           #+#    #+#              #
#    Updated: 2026/11/18 10:38:01 by lesainz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def	ft_count_harvest_iterative():
    days = int(input("Days until harvest: "))
    for day in range(1, days + 1):
        print(f"Days {day}")
    print("Harvest time!")

if __name__ == "__main__":
    ft_count_harvest_iterative()
	