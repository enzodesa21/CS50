#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

//Protótipo da função
int calculate_text (string text);

//Main = recebe o input(texto), chama a função e exibe o output (grade)
int main (void)
{
    //Input: string texto
    txt = get_string("Texto: ");

    //Chamar a função para o texto (txt)
    int grade = calculate_text(txt);

    //Output: Blocos condicionais verificando o valor do resultado da conta e definindo a grade (arredondar o numero)
    if(grade < 1)
    {
        printf("Before Grade 1");
    }

    else if (grade >= 16)
    {
        printf("Grade 16+");
    }

    else if (grade > 1)
    {
        printf("Grade %i", grade);
    }

    printf("\n");
}

//Fazer a depuração completa do texto e aplicar a formula
int calculate_text (string text)
{
    //Contador de letras
    int letras = 0;

    //Contador de palavras
    int palavras = 1;           //palavras + 1, para contar os espaços

    //Contador de frases
    int frases = 0;

    //Loop que percorre todo o texto(caractere por caractere)
    for (int i = 0; text[i] != '\0'; i++)
    {
        //Condicional que conta as letras
        if (isalpha(text[i]))
        {
            letras++;
        }
        //Condicional que conta as palavras
        if (text[i] == ' ')
        {
            palavras++;
        }
        //Condicional que conta as frases
        if (text[i] == '.' || text[i] == '!' ||text[i] == '?')
        {
            frases++;
        }
    }

    //Aplicar calculo a partir do valor dos contadores
    //Variavel resultado
    int resultado = 0;

    // L = (letras / palavras) * 100
    float l = (float) letras / palavras * 100;

    // S = (frases / palavras) * 100
    float s = (float) frases / palavras * 100;

    //Conta
    float conta = 0.0588 * l - 0.296 * s - 15.8;

    //Arredondar o valor para o inteiro mais proximo(round())

    resultado = round(conta);

    return resultado;
}
