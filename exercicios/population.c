#include <cs50.h>
#include <stdio.h>

int main (void)
{
    //Input: O tamanho atual (não pode ser um numero menor que 9)

    int atual;       //População atual

    do
    {
        atual = get_int("População atual: ");
    }
    while (atual < 9);

    //População final (tem que ser maior que o inicial)

    int final;           //População final

    do
    {
        final =get_int("População final: ");
    }
    while (final < atual);

    //Calcular crescimento populacional e contar quantos anos se passaram

    int anos = 0;        //Contador de anos

    while (atual < final)
    {
        int n = atual / 3;         //Nascimentos

        int m = atual / 4;         //Mortes

        atual = atual + n - m;      //Crescimento

        anos++;
    }

    printf("Anos: %i", anos);
    printf("\n");
}
