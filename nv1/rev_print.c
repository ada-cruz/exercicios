/*Assignment name  : rev_print
Expected files   : rev_print.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string, and displays the string in reverse
followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./rev_print "zaz" | cat -e
zaz$
$> ./rev_print "dub0 a POIL" | cat -e
LIOP a 0bud$
$> ./rev_print | cat -e
$ */
#include <unistd.h>

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while(str[i] != '\0')
        i++;
    return (i);
}

void rev_print(char *str)
{
    int i;
    int end;

    i = 0;
    end = ft_strlen(str);
    while(str[i] != '\0')
    {
        write(1, &str[end - 1], 1);
        i++;
        end--;
    }
}

int main(int argc, char **argv)
{
    rev_print(argv[1]);
    write(1, "\n", 1);
}