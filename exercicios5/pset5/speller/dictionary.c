// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

//Words counter
unsigned int word_count = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int index = hash(word);

    node *n = table[index];

    while (n != NULL)
    {
        if (strcasecmp(word, n -> word) == 0)
        {
            retun true;
        }

        n = n -> next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    //Open file
    FILE *file = fopen(dictionary, "r");

    //While thera are words
    while(fscanf(file, "%s", word) == 1)
    {
        //Meke node
        node *n = malloc(sizeof(node));

        //Copy temporary word to node
        strcpy(n -> word, word);

        //Separete then to buckets
        unsigned int index = hash(word);

        //Insert on hash table
        n -> next = table[index];

        word_count++;
    }

    fclose(file);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *n = table[i];

        while (n != NULL)
        {
            node *temp = n -> next;

            free(n);

            n = temp;
        }
    }

    return true;
}
