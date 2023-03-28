/*Assignment name  : ft_strrev
Expected files   : ft_strrev.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that reverses (in-place) a string.

It must return its parameter.

Your function must be declared as follows:

char    *ft_strrev(char *str);*/

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

char *ft_strrev(char *str)
{
    int i;
    int len;
    char aux;

    len = ft_strlen(str);
    i = 0;
    while(i <= len/ 2)
    {
        aux = str[i];
        str[i] = str[len - 1];
        str[len - 1] = aux;
        i++;
        len--;
    }
    return (str);
}