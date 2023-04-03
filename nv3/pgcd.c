/*Assignment name  : pgcd
Expected files   : pgcd.c
Allowed functions: printf, atoi, malloc, free
--------------------------------------------------------------------------------

Write a program that takes two strings representing two strictly positive
integers that fit in an int.

Display their highest common denominator followed by a newline (It's always a
strictly positive integer).

If the number of parameters is not 2, display a newline.

Examples:

$> ./pgcd 42 10 | cat -e
2$
$> ./pgcd 42 12 | cat -e
6$
$> ./pgcd 14 77 | cat -e
7$
$> ./pgcd 17 3 | cat -e
1$
$> ./pgcd | cat -e
$*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int pgcd(int n1, int n2)
{
    int i;
    int result;

    i = 2;
    result = 1;

    while (n1 > i || n2 > i)
    {
        if (n1 % i == 0 && n2 % i == 0)
        {
            n1 = n1 / i;
            n2 = n2 / i;
            result = result * i;
        }
        else 
            i++;
    }
    return (result);
}

int main(int argc, char **argv)
{
    int resultado;

    if (argc != 3)
    {
        write(1, "\n", 1);
        return (1);
    }
    resultado = pgcd(atoi(argv[1]), atoi(argv[2]));
    printf("%d\n", resultado);
    return (0);
}