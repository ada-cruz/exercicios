/*Assignment name  : snake_to_camel
Expected files   : snake_to_camel.c
Allowed functions: malloc, free, realloc, write
--------------------------------------------------------------------------------

Write a program that takes a single string in snake_case format
and converts it into a string in lowerCamelCase format.

A snake_case string is a string where each word is in lower case, separated by
an underscore "_".

A lowerCamelCase string is a string where each word begins with a capital letter
except for the first one.

Examples:
$>./snake_to_camel "here_is_a_snake_case_word"
hereIsASnakeCaseWord
$>./snake_to_camel "hello_world" | cat -e
helloWorld$
$>./snake_to_camel | cat -e
$*/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int count_underline(char *str)
{
    int i;
    int underline;

    i = 0;
    underline = 0;
    while(str[i] != '\0')
    {
        if (str[i] == '_')
            underline++;
        i++;
    }
    return(underline);
}

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

void    snake_to_camel(char *str)
{
    int i;
    int j;
    char *camel;
    
    camel = malloc(sizeof(char) * ft_strlen(str) - count_underline(str) + 1);
    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '_')
            str[i + 1] = str [i + 1] - 32;
        i++;
    }
    i = 0;
    j = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '_')
            i++;
        camel[j] = str[i];
        i++;
        j++;
    }
    camel[j] = '\0';
    write(1, camel, j);
    
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return (1);
    snake_to_camel(argv[1]);
    return (0);
}