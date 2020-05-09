// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

node *word_node(char word[LENGTH + 1])
{
    node *result = malloc(sizeof(node));
    strcpy(result->word, word);
    result->next = NULL;
    return result;
}

int word_count = 0;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    int hash_lookup = hash(word); // Hash the word to compare
    node *traverse;                
    traverse = table[hash_lookup]; // Set list to hash

    // Traversing list
    while (traverse != NULL)
    {
        //Check whether the word is in dictionary
        if (strcasecmp(traverse->word, word) == 0)
        {
            return true;
        }
        traverse = traverse->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    int one_time_hash, i; 
    for (one_time_hash = i = 0; i < strlen(word); ++i)
    {
        one_time_hash += tolower(word[i]);
        one_time_hash += (one_time_hash << 10);
        one_time_hash ^= (one_time_hash >> 6);
    }
    one_time_hash += (one_time_hash << 3);
    one_time_hash ^= (one_time_hash >> 11);
    one_time_hash += (one_time_hash << 15);
    return (one_time_hash % N);
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO
    FILE *dict = fopen(dictionary, "r"); // Open file

    if (dict == NULL)
    {
        return false;
    }

    char word[LENGTH + 1];
    node *tmp;

    //Reads the file provided as the command line argument
    while (fscanf(dict, "%s", word) != EOF) 
    {
        tmp = word_node(word);
        int result = hash(word);
        tmp->next = table[result];
        table[result] = tmp;
        word_count++;
    }
    fclose(dict);
    return true;
}

unsigned int size(void)
{
    // Returns number of words in dictionary if loaded else 0 if not yet loaded
    return word_count;
}

bool unload(void)
{
    // Unloads dictionary from memory, returning true if successful else false
    node *temp; 
    node *traverse;

    for (int i = 0; i < N; i++) // Run for length of table
    {
        if (table[i] != NULL) // If there's no node, ignore
        {
            traverse = table[i]; // Go to each node and free
            while (traverse != NULL)
            {
                temp = traverse->next;
                free(traverse);
                traverse = temp;
            }
            temp = traverse;
            free(temp);
        }
    }
    return true;
}
