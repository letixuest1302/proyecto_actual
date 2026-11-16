# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_harvest_total.py                                :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lesainz <lesainz@student.42madrid.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/12 10:51:04 by lesainz           #+#    #+#              #
#    Updated: 2026/11/16 13:17:30 by lesainz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def	ft_harvest_total(day1: int, day2: int, day3: int) -> None:
	total = day1 + day2 + day3
	print(f"Day 1: {day1}")
	print(f"Day 2: {day2}")
	print(f"Day 3: {day3}")
	print(f"Total harvest: {total}")
	
