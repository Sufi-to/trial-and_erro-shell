#include "simpleshellmain.h"

/**
 * _strwchr - checks for the first occurrence of a character
 * @s: string to be checked
 * @c: character we are supposed to check for
 *
 * Return: a pointer to the first occurrence of c
 */

char *_strwchr(char *s, char c)
{
    int i;

    for (i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == c)
        {
            return (s + i);
        }
    }

    return (NULL);
}

/*
 * motandnefstrtok - this function replicates all the functionalities
 * of the C function "strtok"
 *
 * @stringtobetokenized: the string that is going to be tokenized
 * @delimiters: these are the characters that are going to used
 * to tokenize the string "stringtobetokenized"
 *
 * Description: refer to the first commented out line
 *
 * Return: returns the tokenized string upon sucessful tokenization
 * (or)
 * returns NULL if tokenization fails
 */

char *_strtok(char *stringtobetokenized, char *delimiters)
{
    char *wearehere;
    static char *motnef = NULL;


    if (stringtobetokenized != NULL)
    {
        motnef = stringtobetokenized;
    }

    else if (motnef == NULL)
    {
        return (NULL);
    }

    while (*motnef != '\0' && _strwchr(delimiters, *motnef) != NULL)
    {
        motnef++;
    }

    if (*motnef == '\0')
    {
        return (NULL);
    }

    wearehere = motnef;


    while (*motnef != '\0' && _strwchr(delimiters, *motnef) == NULL)
    {
        motnef++;
    }

    if (*motnef != '\0')
    {
        *motnef = '\0'; 
        motnef++;
    }
    return (wearehere);
}
