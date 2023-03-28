/*Assignment name  : ft_swap
Expected files   : ft_swap.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that swaps the contents of two integers the adresses of which
are passed as parameters.

Your function must be declared as follows:*/

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
    int temp;

    //temp = 5;

    temp = *a;
    *a = *b;
    *b = temp;

}