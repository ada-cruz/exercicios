/*Assignment name  : ft_atoi
Expected files   : ft_atoi.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str to an integer (type int)
and returns it.

It works much like the standard atoi(const char *str) function, see the man.

Your function must be declared as follows:

int	ft_atoi(const char *str);*/
#include <stdio.h>
#include <unistd.h>

int ft_atoi(const char *str)
{
    int i;
    int sign;
    int n;

    i = 0;
    n = 0;
    while (str[i] == 32 || str[i] == '\t' || str[i] == '\n' || str[i] == '\f'
    || str[i] == '\v')
        i++;
    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if (str[i] == '+')
    {
        sign = 1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        n = n * 10;
        n = n + str[i] - '0';
        i++;
    }
    return (sign * n);
}
