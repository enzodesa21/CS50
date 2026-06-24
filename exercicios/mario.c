#include <cs50.h>
#include <stdio.h>

int main (void)
{
    int n;

    do                              //Recebe o valor do usuario
    {
        n = get_int("ALtura: ");
    }
    while (n < 1 || n > 8);

    for(int i = 0; i < n; i++)       //i = a linhas
    {
        for(int k = 0; k < n - (i + 1); k++)   //k = espaços 
        {
            printf(" ");
        }

        for(int j = 0; j <= i; j++)    //j = colunas
        {
            printf("#");
        }
        printf("\n");    //Quebra de linha
    }

}
