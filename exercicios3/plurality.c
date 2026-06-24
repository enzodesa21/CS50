#include <cs50.h>
#include <stdio.h>
#include <string.h>

//Protótipo da função vote
bool vote (string nome_digitado);

//Protótipo da função winner
void winner (void);

//Definir typedef struct candidato (nome e votos)
typedef struct
{
    string name;
    int vote;
}
candidato;

//Array globas de candidatos e contador
#define MAX 9
candidato candidatos[MAX];

int n_candidatos;



int main (int argc, string argv[])
{
    n_candidatos = argc - 1;

    //Preenchendo a array
    for (int i = 0; i < n_candidatos; i++)
    {
        candidatos[i].name = argv[i + 1];
        candidatos[i].vote = 0;
    }

    //Input de quantos votos vão ser
    int n_votos = get_int("Quantos votos serão feitos: ");

    //Loop com a quantidade de votos e chamando a função vote
    for (int i = 0; i < n_votos; i++)
    {
        //Perguntar pelo nome do candidato
        string nome_digitado = get_string("Nome do candidato que ira votar: \n");

        //A cada iteração, a função valida o voto

        //Caso o nome digitado for inválido:
        if(vote(nome_digitado) == false)
        {
            printf("Nome de candidato inválido\n");
        }

    }

    //Chamar a função winner para exibir o vencedor
    winner();

    printf("\n");
}

bool vote (string nome_digitado)
{
    //Vai validar se o nome digitado está dentro da array de candidatos
    for(int i = 0; i < n_candidatos; i++)
    {
        //Para cada candidato
        if(strcmp(nome_digitado, candidatos[i].name) == 0)  //strcmp retona 0 para strings iguais
        {
            candidatos[i].vote++;
            return true;
        }
    }

    return false;
}

//Função void nao retorna valor (void)
void winner (void)
{
    int maior_voto = 0;
    int voto_atual = 0;

    //Identificar o maior numero de votos
    for(int i = 0; i < n_candidatos; i++)
    {
        //Armazenar o maior numero
        voto_atual = candidatos[i].vote;

        if(voto_atual > maior_voto)
        {
            maior_voto = voto_atual;
        }
    }

    //Identificar o candidato com o maior numero de votos
    for(int i = 0; i < n_candidatos; i++)
    {
        //Encontrar o candidato com o maior numero
        if (candidatos[i].vote == maior_voto)
        {
            printf("Vencedor: %s \n", candidatos[i].name);
        }
    }
}
