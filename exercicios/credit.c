#include <cs50.h>
#include <stdio.h>

int main (void)
{
    //Input = numero do cartão de credito

    long numero;

    numero = get_long("Digite o número do cartão: ");

    long n_original = numero;     //Armazena o número do cartão para verificação

    long n_lenght = numero ;     //Armazena o número do cartão para contar o numero de digitos

    //Ler o numero da direita para a esquerda e identificar os digitos

    int posicao = 0;                                   //Identifica a posição do digito (impar ou par)

    int soma = 0;                                      //Armazena os digitos para fazer a soma final

    while(numero > 0)
    {
        int digito = numero % 10;                    //O resto da divisão será o digito

        if (posicao % 2 != 0)             //Posição for impar = * 2
        {
            int conta = digito * 2;

            if (conta >= 10)                    //Digitos que deram mais de dois algarismos
            {
                conta = conta / 10 + conta % 10;
            }

            soma += conta;        //Soma o valor dos digitos
        }

        else             //Posição par = soma
        {
            soma += digito;
        }

        numero = numero / 10;  //Proximo digito

        posicao++;    //Muda a posição

    }

    //Dois primeiros digitos de um cartão

    long n_inicio = n_original;          //Dois primeiros digitos

    while (n_inicio >= 100)
    {
        n_inicio /= 10;
    }

    //Contador para tamanho do número

    int lenght = 0;

    while(n_lenght > 0)
    {
        n_lenght /= 10;
        lenght++;
    }



    if (soma % 10 == 0)         //Cartão valido
    {
        //VISA
        if ((lenght == 13 || lenght == 16) && (n_inicio / 10 == 4))
        {
            printf("Operadora do cartão: VISA");
        }

        //AMEX
        else if ((lenght == 15) && (n_inicio == 34 || n_inicio == 37))
        {
            printf("Operadora do cartão: AMEX");
        }

        //MasterCard
        else if ((lenght == 16) && (n_inicio >= 51 && n_inicio <= 55))
        {
            printf("Operadora do cartão: MasterCard");
        }

        else
        {
            printf("INVÁLIDO");
        }
    }

    else
    {
        printf("INVÁLIDO");
    }

    printf("\n");
}
