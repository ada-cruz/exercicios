/*Assignment name  : union
Expected files   : union.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.

The display will be in the order characters appear in the command line, and
will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Example:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>*/
#include <unistd.h>
int check(int c, char *str, int index)
{
    int i;

    i = 0;
    while(i < index)
    {
        if (str[i] == c)
            return 0;
        i++;
    }
    return 1;
}

void ft_union(char *str1, char *str2)
{
    int i;
    int j;
    int k;

    i = 0;
    j = 0;
    k = 0;
    while(str1[i] != '\0')
        i++;
    while(str2[j] != '\0')
    {
        str1[i] = str2[j];
        i++;
        j++;
    }
    i--;
    while(k <= i)
    {
        if(check(str1[k], str1, k) == 1)
            write (1, &str1[k], 1);
        k++;
    }
    write (1, "\n", 1);
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        write(1, "\n", 1);
        return (1);
    }
    ft_union(argv[1], argv[2]);
}