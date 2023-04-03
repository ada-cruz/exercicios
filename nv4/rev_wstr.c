/*Assignment name  : rev_wstr
Expected files   : rev_wstr.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string as a parameter, and prints its words in
reverse order.

A "word" is a part of the string bounded by spaces and/or tabs, or the
begin/end of the string.

If the number of parameters is different from 1, the program will display
'\n'.

In the parameters that are going to be tested, there won't be any "additional"
spaces (meaning that there won't be additionnal spaces at the beginning or at
the end of the string, and words will always be separated by exactly one space).

Examples:

$> ./rev_wstr "You hate people! But I love gatherings. Isn't it ironic?" | cat -e
ironic? it Isn't gatherings. love I But people! hate You$
$>./rev_wstr "abcdefghijklm"
abcdefghijklm
$> ./rev_wstr "Wingardium Leviosa" | cat -e
Leviosa Wingardium$
$> ./rev_wstr | cat -e
$
$>*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while(str[i] != '\0')
        i++;
    return (i);
}

void rev_wstr(char *str)
{
    int fim;
    int i;
    int j;
    char *newstr;

    newstr = malloc(sizeof (char) * ft_strlen(str) + 1);
    if (!newstr)
        return ;
    fim = ft_strlen(str) - 1;
    newstr[fim + 1] = '\0';
    i = 0;
    j = 0;
    while (fim >= 0)
    {
        if (str[fim] == ' ' || str[fim] == '\t' || fim == 0)
        {
            if (fim > 0)
                i = fim + 1;
            else
                i = 0;
            while (str[i] != ' ' && str[i] != '\0' && str[i] != '\t')
            {
                newstr[j] = str[i];
                i++;
                j++;
            }
            newstr[j] = ' ';
            j++;
        }
        fim--;
    }
    write(1, newstr, j - 1);
    write(1, "\n", 1);
    free (newstr);
}

int main(int argc, char **argv)
{

    if (argc != 2)
    {
        write(1, "\n", 1);
        return (1);
    }
    rev_wstr(argv[1]);
    return (0);

}