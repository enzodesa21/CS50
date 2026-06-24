#include<stdio.h>
#include<cs50.h>
#include<ctype.h>
#include<string.h>

//Prototipo
string change_letter (string texto, string key);

int main (int argc, string argv[])
{
    //Validar argc
    if (argc != 2)
    {
        printf("Número de argumentos inválidos\n");
        return 1;
    }

    //Validar quantidade de caracteres no argv == [25]
    if (strlen(argv[1]) != 26)
    {
        printf("Número de caracteres inválido\n");
        return 1;
    }


    //Validar se ha apenas letras (eliminando os numeros)
    for (int j = 0; argv[1][j] != '\0'; j++)
    {
        if (!isalpha(argv[1][j]))
        {
            printf("Caracteres inválidos\n");
            return 1;
        }
    }

    //Validar se nenhuma letra se repete (maiusculas e minusculas não se diferenciam)
    for (int k = 0; argv[1][k] != '\0'; k++)
    {
        for (int l= 0; l < k; l++)
        {
            char lp = tolower(argv[1][l]);

            char kp = tolower(argv[1][k]);

            if (lp == kp)
            {
                printf("Há uma repetição de caracteres\n");
                return 1;
            }
        }
    }

    //Key = novo abc
    string key = argv[1];

    //Input: texto
    string texto = get_string("Texto: ");

    //Chamar função
    string texto_cifrado = change_letter(texto, key);

    //Output: texto criptografado
    printf("Texto cifrado: %s", texto_cifrado);
    printf("\n");
}

string change_letter (string texto, string key)
{
    //Loop para cada caractere
    for (int i = 0; texto[i] != '\0'; i++)
    {
        //Se for letra (dividir entre maiuscula e minuscula)
        if (isalpha(texto[i]))
        {

            //Converter
            char letra = tolower(texto[i]);

            //Trocar o caractere pela key
            int numeracao = letra - 'a';

            char letrac = key[numeracao];

            if (isupper(texto[i]))
            {
                texto[i] = toupper(letrac);
            }
            else if (islower(texto[i]))
            {
                texto[i] = tolower(letrac);
            }

        }
    }

    //Retornar nova palavra
    return texto;
}
