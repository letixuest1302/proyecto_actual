# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_seed_inventory.py                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lesainz <lesainz@student.42madrid.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/12 10:55:22 by lesainz           #+#    #+#              #
#    Updated: 2026/11/18 10:21:54 by lesainz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def ft_seed_inventory(seed_type: str, quantity: int, unit: str) -> None:
    capitalized_seed = seed_type.capitalize()
    
    if unit == "packets":
        print(f"{capitalized_seed} seeds: {quantity} packets available")
    elif unit == "grams":
        print(f"{capitalized_seed} seeds: {quantity} grams total")
    elif unit == "area":
        print(f"{capitalized_seed} seeds: covers {quantity} square meters")

if __name__ == "__main__":
    ft_seed_inventory("pear", 6, "area")