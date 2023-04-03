/*Assignment name  : sort_int_tab
Expected files   : sort_int_tab.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

void sort_int_tab(int *tab, unsigned int size);

It must sort (in-place) the 'tab' int array, that contains exactly 'size'
members, in ascending order.

Doubles must be preserved.

Input is always coherent.*/
#include <stdio.h>
void    sort_int_tab(int *tab, unsigned int size)
{
    int aux;
    unsigned int i;
    unsigned int j;

    i = 0;
    while(i < size)
    {
        j = i;
        while (j < size)
        {
            if (tab[i] > tab[j])
            {
                aux = tab[i];
                tab[i] = tab[j];
                tab[j] = aux;
            }
            j++;
        }
        i++;
    }
}

int main(void)
{
    int numeros[] = {5, 21, -50, 24, 42};
    sort_int_tab(numeros, 5);
    printf("%d\n", numeros[0]);
    printf("%d\n", numeros[1]);
    printf("%d\n", numeros[2]);
    printf("%d\n", numeros[3]);
    printf("%d\n", numeros[4]);

    return (0);
}