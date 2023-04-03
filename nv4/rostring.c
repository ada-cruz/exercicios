/*Assignment name  : rostring
Expected files   : rostring.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string and displays this string after rotating it
one word to the left.

Thus, the first word becomes the last, and others stay in the same order.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

Words will be separated by only one space in the output.

If there's less than one argument, the program displays \n.

Example:

$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring "first" "2" "11000000"
first
$>
$>./rostring | cat -e
$
$>*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

void rostring(char *str)
{
    int i;
    char *newstr;
    int fim;
    int x;
    int checker;

    x = 0;
    i = 0;
    checker = 0;
    fim = ft_strlen(str) - 1;
    newstr = malloc(sizeof (char) * ft_strlen(str) + 1);
    if (!newstr)
        return ;
    newstr[fim] = '\0';
    while (str[i] == ' ' || str[i] == '\t') // avanço no inicio os espaços possiveis de existir.
        i++;
    while (str[fim] == ' ' || str[fim] == '\t') // avanço o fim os espaços no final possiveis de existir.
        fim--;
    while (str[i] != ' ' && str[i] != '\t')
        i++;
    i++;
    while(i <= fim)
    {
        newstr[x] = str[i];
        x++;
        i++;
    }
    if (x != 0)
    {
        newstr[x] = ' ';
        x++;
    }
    i = 0;
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    while (str[i] != ' ' && str[i] != '\t')
    {
        newstr[x] = str[i];
        i++;
        x++;
    }
    x = 0;
    while (newstr[x] != '\0')
    {
        if (newstr[x] == ' ' || newstr[x] == '\t')
            checker = 1;
        else
        {
            if(checker)
                write(1, " ", 1);
            checker = 0;
            write(1, &newstr[x], 1);
        }
        x++;
    }
    //write(1, newstr, x);
    
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        write(1, "\n", 1);
        return (1);
    }
    rostring(argv[1]);
    write(1, "\n", 1);
    return (0);
}