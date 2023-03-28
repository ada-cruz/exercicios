/*Assignment name	: ft_strspn
Expected files	: ft_strspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the strspn function 
(man strspn).

The function should be prototyped as follows:

size_t	ft_strspn(const char *s, const char *accept);*/
#include <stdio.h>
size_t	ft_strspn(const char *s, const char *accept)
{
    size_t i;
    size_t j;

    i = 0;
    while (s[i] != '\0')
    {
        j = 0;
        while (accept[j] != '\0')
        {
            if (s[i] == accept[j])
            {
                i++;
                j++;
            }    
        }
    }
}
int main(int argc, char **argv)
{
    size_t tamanho;

    if (argc != 3)
        return (1);
    tamanho = ft_strspn(argv[1], argv[2]);
    return (0);
}