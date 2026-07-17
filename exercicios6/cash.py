from cs50 import get_float

while True:
    cash = float (get_float("Cash owed: "))

    if cash >= 0:
        break

n_moeda = 0

while cash > 0:
    if cash >= 0.25:
       cash = cash - 25
       n_moeda += 1

    elif cash >= 0.10:
        cash = cash - 0.10
        n_moeda += 1

    elif cash >= 0.05:
        cash = cash - 0.05
        n_moeda += 1

    elif cash >= 0.01:
        cash = cash - 0.01
        n_moeda += 1


print(f"{n_moeda}")


