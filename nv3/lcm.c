/*Assignment name  : lcm
Expected files   : lcm.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function who takes two unsigned int as parameters and returns the
computed LCM of those parameters.

LCM (Lowest Common Multiple) of two non-zero integers is the smallest postive
integer divisible by the both integers.

A LCM can be calculated in two ways:

- You can calculate every multiples of each integers until you have a common
multiple other than 0

- You can use the HCF (Highest Common Factor) of these two integers and
calculate as follows:

	LCM(x, y) = | x * y | / HCF(x, y)

  | x * y | means "Absolute value of the product of x by y"

If at least one integer is null, LCM is equal to 0.

Your function must be prototyped as follows:

  unsigned int    lcm(unsigned int a, unsigned int b);*/
#include <stdio.h>
unsigned int    lcm(unsigned int a, unsigned int b)
{
    int i;
    unsigned int result;
    int checker;

    i = 2;
    result = 1;
    checker = 0;
    while (a > 1 || b > 1)
    {
        if (a % i == 0)
        {
            a = a / i;
            checker = 1;
        }
        if (b % i == 0)
        {
            b = b / i;
            checker = 1;
        }
        if (checker == 1)
        {
            checker = 0;
            result = result * i;
        }
        else
            i++;
        
    }
    return (result);
}

int main(void)
{
    unsigned int retorno;

    retorno = lcm(15, 20);
    printf("%u\n", retorno);
}