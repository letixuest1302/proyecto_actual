def ft_count_harvest_recursive() -> None:
    days = int(input("Days until harvest: "))

    def helper(current: int, target: int) -> None:
        if current > target:
            print("Harvest time!")
            return
        print(f"Day {current}")
        helper(current + 1, target)

    helper(1, days)
