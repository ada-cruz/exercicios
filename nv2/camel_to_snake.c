/*Assignment name  : camel_to_snake
Expected files   : camel_to_snake.c
Allowed functions: malloc, realloc, write
--------------------------------------------------------------------------------

Write a program that takes a single string in lowerCamelCase format
and converts it into a string in snake_case format.

A lowerCamelCase string is a string where each word begins with a capital letter
except for the first one.

A snake_case string is a string where each word is in lower case, separated by
an underscore "_".

Examples:
$>./camel_to_snake "hereIsACamelCaseWord"
here_is_a_camel_case_word
$>./camel_to_snake "helloWorld" | cat -e
hello_world$
$>./camel_to_snake | cat -e
$*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int    countwords(char *str)
{
    int i;
    int count;

    i = 0;
    count = 1;
    while (str[i] != '\0')
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            count++;
        i++;
    }
    return (count);
}

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return (i);
}

void    camel_to_snake(char *str)
{
    int i;
    int j;
    int z;
    char *snake;

    i = 0;
    j = 0;
    z = 0;
    snake = malloc(sizeof(char) * ft_strlen(str) + countwords(str));
    while(str[i] != '\0')
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
                snake[j] = '_';
                j++;
        }
        snake[j] = str[i];
        i++;
        j++;
    }
    while(snake[z] != '\0')
    {
        if (snake[z] >= 'A' && snake[z] <= 'Z')
            snake[z] = snake[z] + 32;
        z++;
    }
    write(1, snake, j);
}

int main(int argc, char **argv)
{
    camel_to_snake(argv[1]);
    return (0);
}