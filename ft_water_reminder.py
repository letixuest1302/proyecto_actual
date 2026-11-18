# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_water_reminder.py                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lesainz <lesainz@student.42madrid.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/12 10:53:36 by lesainz           #+#    #+#              #
#    Updated: 2026/11/18 10:17:51 by lesainz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def ft_water_reminder():
	moisture = int(input("Enter soil moisture level: "))
	if moisture < 30:
		print("Time to water the plants!")
	else:
		print("Soil moisture is sufficient.")


if __name__ == "__main__":
    ft_water_reminder()