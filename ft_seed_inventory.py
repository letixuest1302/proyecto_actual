# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_seed_inventory.py                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lesainz <lesainz@student.42madrid.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/12 10:55:22 by lesainz           #+#    #+#              #
#    Updated: 2026/11/16 11:44:55 by lesainz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def ft_seed_inventory(seed_type: str, quantity: int, unit: str) -> None;
    capitalized_seed = seed_type.capitalize()
    
    if unit == "packets":
        print(f"{capitalized_seed} seeds: {quantity} packets available")
    elif unit == "grams":
        print(f"{capitalized_seed} seeds: {quantity} grams total")
    elif unit == "area":
        print(f"{capitalized_seed} seeds: covers {quantity} square meters")