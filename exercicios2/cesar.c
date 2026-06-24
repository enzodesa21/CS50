#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>

//Prototipo da função ceasar
string cesar (string txt, int key);

int main (int argc, string argv[])
{
    //Validar argc == 2
    if (argc != 2)
    {
        printf("Número de argumentos invalido\n");
        return 1;
    }

    //Validar argv como numero
    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Caracteres inválidos\n");
            return 1;
        }
    }

    //Converter argv[1] para int (key)
    //key % 26

    int key = atoi(argv[1]);

    key %= 26;

    //Input texto
    string texto = get_string("Texto: ");

    //Chamar função cesar e key para texto
    string cripto = cesar(texto, key);

    //Output texto criptografado
    printf("Texto criptografado: %s", cripto);

    printf("\n");
}

string cesar (string txt, int key)
{
    //Loop para cada caractere txt[i]
    for (int i = 0; txt[i] != '\0'; i++)
    {
        //Se for letra
        if (isalpha(txt[i]))
        {
            //Maiuscula = converter para 0-25 e criptografar
            if (isupper(txt[i]))
            {
                txt[i] = (txt[i] - 'A' + key) % 26 + 'A';
            }

            //Minuscula = converter 0-25 e criptografar
            else if (islower(txt[i]))
            {
                txt[i] = (txt[i] - 'a' + key) % 26 + 'a';
            }
        }
        //Senão, manter
    }
    //Restornar resultado
    return txt;
}
