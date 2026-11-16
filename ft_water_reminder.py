# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_water_reminder.py                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lesainz <lesainz@student.42madrid.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/12 10:53:36 by lesainz           #+#    #+#              #
#    Updated: 2026/11/16 12:26:43 by lesainz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def ft_water_reminder():
	moisture = int(input("Enter soil moisture level: "))
	if moisture < 30:
		print("Time to water th plants!")
	else:
		print("Soil mpisture is sufficient.")