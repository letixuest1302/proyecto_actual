# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_count_harvest_recursive.py                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lesainz <lesainz@student.42madrid.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/12 10:54:54 by lesainz           #+#    #+#              #
#    Updated: 2026/11/16 13:07:08 by lesainz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def	ft_count_harvest_recursive():
	day = int(input("Days until harvest: "))
	
	def helper(current, target):
		if current > target:
			print("Harvest time!")
			return
		print(f"Day {current}")
		helper(current + 1, target)
		
	helper(1, days)