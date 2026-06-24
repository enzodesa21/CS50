#include <cs50.h>
#include <stdio.h>
#include <strings.h>
#include <ctype.h>

//Array de pontuação referente a cada letra

int pontos[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int contador_pontos (string word);            //Prototipo

int main (void)
{
    //Solicitar ao usuario 2 palavras (P1 e P2)

    string palavra1 = get_string("Jogador 1: ");

    string palavra2 = get_string("Jogador 2: ");

    //Calcular os pontos de cada palavra

    int score1 = contador_pontos(palavra1);

    int score2 = contador_pontos(palavra2);

    //Exibir o resultado (Vencedor ou empate)

    if (score1 > score2)
    {
        printf("O jogador 1 ganhou!");
    }

    else if (score2 > score1)
    {
        printf("O jogador 2 ganhou!");
    }

    else if (score1 == score2)
    {
        printf("Empate");
    }

    printf("\n");
}

int contador_pontos(string word)         //Verifica a string e calcula os pontos referente a array pontos
{

    int total = 0;                 //Total de pontos

    for (int i = 0; word[i] != '\0'; i++)          //Percoree a palavra caractere por caractere
    {
        char letra = word[i];            //Caractere atual da palavra

        if (isalpha(letra))               //Verifica se é uma letra, se sim, converte para minuscula
        {
            letra = tolower(letra);

            int indice = letra -'a';           //Calcula o indice da letra na array de pontos (ASCII)

            total = pontos[indice] + total;
        }

    }

    return total;           //Retorna a pontuação total
}
