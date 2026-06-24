#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main (void)
{
    //Input = Valor do troco (Não pode ser : negativo ou 0. Tem que ser float)
    float v;

    do
    {
        v = get_float("Valor do troco: ");
    }
    while (v <= 0);

    int c = round (v * 100);

    //Constantes = valores de cada moeda

    const int moeda_25 = 25;

    const int moeda_10 = 10;

    const int moeda_5 = 5;

    const int moeda_1 = 1;

    //Contador de moedas

    int m = 0;

    //Loop com condiçoes
    //Se ainda tiver troco, usar a moeda com maior valor, senão vá para a proxima

    while (c > 0)
    {
        if (c >= moeda_25)
        {
            c -= moeda_25;
            m++;
        }

        else if (c >= moeda_10)
        {
            c -= moeda_10;
            m++;
        }

        else if (c >= moeda_5)
        {
            c -= moeda_5;
            m++;
        }

        else
        {
            c -= moeda_1;
            m++;
        }


    }
    //Exibir o numero de moedas utilizadas
    printf("Total de moedas usadas: %i", m);
    printf("\n");

}
