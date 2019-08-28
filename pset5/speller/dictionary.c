#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

//Global variables
int word_counter = 0;
int index = 0;

typedef struct node
{
    bool is_word;

    struct node* children[27];
}
node;

node *root;
node *trav;
node *newnode;

//Recursive function that frees the nodes in trie
bool unload_node(node* ptr)
{
    //Checks every node in the trie
    for (int i = 0; i < 26; i++)
    {
        if (ptr->children[i] != NULL)
        {
            unload_node(ptr->children[i]);
        }
    }

    free(ptr);

    return true;
}


// Returns true if word is in dictionary else false
bool check(const char *word)
{

    trav = root;

    for (int i = 0; i < strlen(word); i++)
    {

        char c = word[i];

        if (isupper(c))
        {
            index = tolower(c) - 'a';
        }

        else if (islower(c))
        {
            index = c - 'a';
        }

        else if (c == '\'' && i > 0)
        {
            index = 26;
        }


        //
        if (trav->children[index] == NULL)
        {
            return false;
        }

        trav = trav->children[index];
    }

    if (trav->is_word == true)
    {
        return true;
    }

    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{

    //We open the dictionary
    FILE* infile = fopen(dictionary, "r");

    //We check if the dictionary can be opened, in case it cannot be opened, we print an error and return false
    if (infile == NULL)
    {
        fprintf(stderr, "%s could not be loaded to read\n", dictionary);
        fclose(infile);
        unload();
        return false;
    }

    //
    char word[LENGTH+1] = {'\0'};

    // We allocate memory on the heap for a root of the trie
    root = calloc(1, sizeof(node));

    //We scan each word from the text with the words of the dictionary until we reach the EOF
    while (fscanf(infile, "%s", word) == 1)
    {

        trav = root;

        //For every word in the dictionary, iterate through the trie
        for (int i = 0; i < strlen(word); i++)
        {

            char c = word[i];

            if (isupper(c))
            {
                index = tolower(c) - 'a';
            }

            else if (islower(c))
            {
                index = c - 'a';
            }

            else if (c == '\'')
            {
                index = 26;
            }

            //If the path has not been created, we allocate memory for a new node
            if (trav->children[index] == NULL)
            {
                newnode = calloc(1, sizeof(node));

                if (newnode == NULL)
                {
                    unload();
                    return false;
                }

                //We assign the path created
                trav->children[index] = newnode;
                trav = newnode;
            }

            else
            {
                trav = trav->children[index];
            }
        }

        //When finished loading word, we set the bool is_word to true
        trav->is_word = true;

        //We increase the word counter by one
        word_counter++;
    }

    fclose(infile);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return word_counter;

    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    return unload_node(root);
}
