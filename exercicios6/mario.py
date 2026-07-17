while True:
    altura = int (input("Altura: "))

    if 1 <= altura <= 8:
        break

for i in range(altura):
    for j in range(altura):

        if j < (altura - i - 1):
            print(" ", end = "")

        else:
            print("#", end = "")

    print()


