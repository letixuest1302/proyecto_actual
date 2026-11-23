def ft_count_harvest_iterative() -> None:
    day = int(input("Days until harvest: "))
    for day in range(1, day + 1):
        print(f"Day {day}")
    print("Harvest time!")
