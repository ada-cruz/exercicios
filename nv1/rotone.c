/*Write a program that takes a string and displays it, replacing each of its
letters by the next one in alphabetical order.

'z' becomes 'a' and 'Z' becomes 'A'. Case remains unaffected.

The output will be followed by a \n.

If the number of arguments is not 1, the program displays \n.

Example:

$>./rotone "abc"
bcd
$>./rotone "Les stagiaires du staff ne sentent pas toujours tres bon." | cat -e
Mft tubhjbjsft ev tubgg of tfoufou qbt upvkpvst usft cpo.$
$>./rotone "AkjhZ zLKIJz , 23y " | cat -e
BlkiA aMLJKa , 23z $
$>./rotone | cat -e
$
$>
$>./rotone "" | cat -e
$
$>*/
// a = 97     z = 122
// A = 65     Z = 90
#include <unistd.h>

void rotone(char *str)
{
    int i;
    int next;
    int casez;

    i = 0;
    while (str[i] != '\0')
    {
        next = str[i];
        if ((str[i] >= 65 && str[i] < 90) || (str[i] >= 97 && str[i] < 122))
            next = str[i] + 1;
        else if (str[i] == 122 || str[i] == 90)
            next = str[i] - 25;
        i++;
        write(1, &next, 1);
    }

}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        write(1, "\n", 1);
        return (0);
    }
    rotone(argv[1]);
    write(1, "\n", 1);

    return (0);
}