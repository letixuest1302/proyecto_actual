def ft_water_reminder() -> None:
    moisture = int(input("Days since last watering: "))
    if moisture > 2:
        print("Water the plants!")
    else:
        print("Plants are fine")
