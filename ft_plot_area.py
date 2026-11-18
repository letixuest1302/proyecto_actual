# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_plot_area.py                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lesainz <lesainz@student.42madrid.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/12 10:48:42 by lesainz           #+#    #+#              #
#    Updated: 2026/11/18 10:16:14 by lesainz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def	ft_plot_area():
	length = int(input("Enter lenght: "))
	width = int(input("Enter width: "))
	area = lenght * width
	print(f"Area: {area}")

if __name__ == "__main__":
    ft_plot_area()