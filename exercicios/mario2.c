#include <cs50.h>
#include <stdio.h>

int main (void)
{
    int n;

    do
    {
        n = get_int("Altura: ");
    }
    while (n < 1 || n > 8);

    for (int i = 0; i < n; i++)            // i = Oque sera feito em cada linha
    {
        for (int k = 0; k < n - (i + 1); k++)
        {
            printf(" ");
        }

        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

            printf("  ");          //Espaçoes entre as escadas

        for (int h = 0; h <= i; h++)  //Segunda escada (não precisa de espaços)
        {
            printf("#");
        }

        printf("\n");          //Pular linha a cada fim de loop
    }
}
