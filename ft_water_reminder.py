# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_water_reminder.py                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lesainz <lesainz@student.42madrid.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/12 10:53:36 by lesainz           #+#    #+#              #
#    Updated: 2026/11/16 13:08:39 by lesainz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def ft_water_reminder():
	moisture = int(input("Enter soil moisture level: "))
	if moisture < 30:
		print("Time to water the plants!")
	else:
		print("Soil moisture is sufficient.")