/*Assignment name  : ft_strdup
Expected files   : ft_strdup.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Reproduce the behavior of the function strdup (man strdup).

Your function must be declared as follows:

char    *ft_strdup(char *src);*/
#include <stdlib.h>
#include <stdio.h>
int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

char    *ft_strdup(char *src)
{
    int i;
    char *newstr;

    newstr = malloc(sizeof (char) * ft_strlen(src) + 1);
    if (!newstr)
        return NULL;
    i = 0;
    while (src[i] != '\0')
    {
        newstr[i] = src[i];
        i++; 
    }
    newstr[i] = '\0';
    return (newstr);
}
