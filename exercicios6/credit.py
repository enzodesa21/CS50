numero = input("Número do cartão: ")

soma = 0
alternar = False

# Luhn
for i in range(len(numero) - 1, -1, -1):
    digito = int(numero[i])

    if alternar:
        digito *= 2

        if digito > 9:
            digito = digito // 10 + digito % 10

    soma += digito
    alternar = not alternar

primeiros2 = int(numero[:2])
length = len(numero)

# Verificação
if soma % 10 == 0:

    if length == 15 and (primeiros2 == 34 or primeiros2 == 37):
        print("AMEX")

    elif length == 16 and 51 <= primeiros2 <= 55:
        print("MASTERCARD")

    elif (length == 13 or length == 16) and str(numero[0]) == "4":
        print("VISA")

    else:
        print("INVALID")

else:
    print("INVALID")


