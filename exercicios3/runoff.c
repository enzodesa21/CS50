#include <cs50.h>
#include <stdio.h>
#include <string.h>

//Maximo de candidatos
#define MAX 9
#define MAX_VOTERS 9
#define MAX_CANDIDATES 9

//Prototypes
bool vote(int voter, int rank, string name);

void tabulate(void);

bool print_winner(void);

int find_min(void);

bool is_tie(int min);

void eliminate(int min);

//Datatype candidato
typedef struct
{
    string name;
    int vote;
    bool eliminated;
}
candidato;

//Array de candidatos
candidato candidatos[MAX];

//Array de preferências(memoria de todos os votos)
int preferences[MAX_VOTERS][MAX_CANDIDATES];

int n_candidatos;

int n_voters;

int main(int argc, string argv[])
{
    n_candidatos = argc - 1;

    for (int i = 0; i < n_candidatos; i++ )
    {
        candidatos[i].name = argv [i + 1];
        candidatos[i].vote = 0;
        candidatos[i].eliminated = false;
    }

    //Input de votos
    n_voters = get_int("Quantidade de eleitores: \n");

    //Para cada eleitor
    for (int voter = 0; voter < n_voters; voter++)
    {
        //Para cada rank (preferência)
        for (int rank = 0; rank < n_candidatos; rank++)
        {
            string name = get_string("Preferencia %i: \n", rank + 1);

            //Verificar nome
            if (!vote(voter, rank, name))
            {
                printf("Nome do candidato inválido\n");
                return 0;
            }
        }
    }

    bool winner;

    do
    {
        //Resetar votos
        for (int i = 0; i < n_candidatos; i++)
        {
            candidatos[i].vote = 0;
        }

        //Computar os votos
        tabulate();

        //Verificar se há um vencedor
        winner = print_winner();
        if (winner == true)
        {
            return 0;
        }

        //|Verificar o mínimo de votos para eliminação
        int min = find_min();

        //Verificar se ha um empate
        bool tie = is_tie(min);
        if (tie == true)
        {
            printf("A eleição terminou empatada\n");
            return 0;
        }

        //Eliminar candidato com o n de votos menor do que min
        eliminate(min);
    }
    while(winner == false);

    printf("\n");
}

//Verificação das preferências do eleitor
bool vote(int voter, int rank, string name)
{
    for (int i = 0; i < n_candidatos; i++)
    {
        //Procurar pelo nome digitado na array
        if (strcmp(name, candidatos[i].name) == 0)
        {
            //Atualizar a array preferences
            preferences[voter][rank] = i;

            return true;
        }
    }

    return false;
}

//Atuliza a contagem de votos para cada candidato
void tabulate(void)
{
    for (int i = 0; i < n_voters; i++)
    {
        for (int j = 0; j < n_candidatos; j++)
        {
            int index = preferences[i][j];

            if (candidatos[index].eliminated == false)
            {
                candidatos[index].vote++;
                break;
            }
        }
    }
}

//Verificar se houve vencedor ou não
bool print_winner(void)
{
    for (int i = 0; i < n_candidatos; i++)
    {
        //Verificar n de votos
        if (candidatos[i].vote > n_voters / 2)
        {
            printf("%s\n", candidatos[i].name);
            return true;
        }
    }

        return false;
}

//Definir o mínimo de votos para decidir quem vai ser eliminado
int find_min(void)
{
    int min = n_voters;
    int voto_atual = 0;

    for (int i = 0; i < n_candidatos; i++)
    {
        if (candidatos[i].eliminated == false)
        {
            voto_atual = candidatos[i].vote;

            if (voto_atual < min)
            {
                min = voto_atual;
            }

        }
    }

    return min;
}

//Verificar se ha empate ou não para dar continuidade a eleição
bool is_tie(int min)
{
    for (int i = 0; i < n_candidatos; i++)
    {
        if (candidatos[i].eliminated == false)
        {
            if (candidatos[i].vote != min)
            {
                return false;
            }
        }
    }

        return true;
}

//Verifica quem será eliminado
void eliminate(int min)
{
    for (int i = 0; i < n_candidatos; i++)
    {
        if (candidatos[i].vote == min)
        {
            candidatos[i].eliminated = true;
        }
    }
}
