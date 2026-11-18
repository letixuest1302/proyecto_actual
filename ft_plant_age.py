# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_plant_age.py                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lesainz <lesainz@student.42madrid.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/12 10:53:10 by lesainz           #+#    #+#              #
#    Updated: 2026/11/18 10:17:30 by lesainz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def ft_plant_age():
	age = int(input("Enter plant age in days: "))
	if age > 60:
		print("Plant is ready to harvest!")
	else:
		print("Plant is not ready to harvest yet.")


if __name__ == "__main__":
    ft_plant_age()