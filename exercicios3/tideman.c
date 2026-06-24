#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 9

//Pares de candidatos
typedef struct
{
    int winner;
    int loser;
}
pair;

//Array de pair
pair pairs[MAX * (MAX - 1) / 2];

//Array de candidatos
string candidates[MAX];

//Array de preferencias
int preferences[MAX][MAX];

//Array de ranks
int ranks[MAX];

//Array de locked
bool locked[MAX][MAX];

//Variaveis globais
int pairs_count = 0;
int candidate_count;
int voter_count;

//Prototype das funções
bool vote(int rank, string name);

void record_preferences(void);

void add_pairs(void);

void sort_pairs(void);

void lock_pairs(void);

bool cycle (int winner, int loser);

void print_winner(void);

//Controle de fluxo
int main(int argc, string argv[])
{
    //Numero de candidatos
    candidate_count = argc - 1;

    //Preencher array de candidatos
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    //Definir locked para falso
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    //Numero de eleitores
    voter_count = get_int("Numero de eleitores: \n");

    //Guardar as preferencias de cada eleitor
    for (int voter = 0; voter < voter_count; voter++)
    {
        for (int rank = 0; rank < candidate_count; rank++)
        {
            string name = get_string("Rank %i: \n", rank + 1);

            if (!vote(rank, name))
            {
                printf("Nome do candidato inválido\n");
                return 0;
            }
        }

        //Preencher a array de preferencias
        record_preferences();
    }

    //Separar os pares
    add_pairs();

    //Classifica os pares
    sort_pairs();

    //Controle de ciclo dos pares
    lock_pairs();

    //Exibir o vencedor
    print_winner();
}

bool vote(int rank, string name)
{
    //Verificar candidatos
    for (int i = 0; i < candidate_count; i++)
    {
        if(strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }

    return false;
}

void record_preferences(void)
{
    //Passar por cada rank
    for (int i = 0; i < candidate_count; i++)
    {
        //Quantas vezes o candidato i foi preferido pelo j
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
        }
    }
}

void add_pairs(void)
{
    //Criar pares para cada candidato
    for (int i = 0; i < candidate_count; i++)
    {
        //Para cada candidato (excluindo as repetiçoes)
        for (int j = i + 1; j < candidate_count; j++)
        {
            if (preferences[i][j] < preferences[j][i])
            {
                pairs[pairs_count].winner = j;
                pairs[pairs_count].loser = i;
                pairs_count++;
            }

            else if (preferences[j][i] < preferences[i][j])
            {
                pairs[pairs_count].winner = i;
                pairs[pairs_count].loser = j;
                pairs_count++;
            }
        }
    }
}

void sort_pairs(void)
{
    int now_pair = 0;
    int more_pair = 0;
    int index = 0;

    //Classificar a array pairs em ordem de força
    for (int i = 0; i < pairs_count; i++)
    {
        more_pair = 0;     // resetar
        index = i;         // assumir que o maior é o atual

        for (int j = i; j < pairs_count; j++)
        {
            now_pair = preferences[pairs[j].winner][pairs[j].loser];

            if (now_pair > more_pair)
            {
                more_pair = now_pair;
                index = j;
            }
        }

        pair temp_index;

        temp_index = pairs[i];
        pairs[i] = pairs[index];
        pairs[index] = temp_index;
    }
}

void lock_pairs(void)
{
    //Para cada par, definir setas
    for (int i = 0; i < pairs_count; i++)
    {
        int winner = pairs[i].winner;
        int loser = pairs[i].loser;

        if (!cycle(winner, loser))
        {
            locked[winner][loser] = true;
        }
    }
}

bool cycle (int winner, int loser)
{
    if (loser == winner)
    {
        return true;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        if (locked[loser][i])
        {
            if (cycle(winner, i))
            {
                return true;
            }
        }
    }

    return false;
}

void print_winner(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        bool seta = false;

        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[j][i] == true)
            {
                seta = true;
            }
        }

        if (seta == false)
        {
            printf("%s\n", candidates[i]);
        }
    }
}
