def main():

    txt = str(input("Texto: "))

    grade = calculate_grade(txt)

    if grade < 1:
        print("Before Grade 1")

    elif grade >= 16:
        print("Grade 16+")

    elif grade > 1:
        print(f"Grade {grade}")


def calculate_grade(txt):

    letras = 0

    palavras = 1

    frases = 0

    for caractere in txt:

        if caractere.isalpha():
            letras += 1

        if caractere == ' ':
            palavras += 1

        if caractere in ['.', '!', '?']:
            frases += 1

    l = (letras / palavras) * 100
    s = (frases / palavras) * 100

    conta = 0.0588 * l - 0.296 * s - 15.8

    resultado = round(conta)

    return resultado

main()
