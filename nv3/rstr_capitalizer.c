/*Assignment name  : rstr_capitalizer
Expected files   : rstr_capitalizer.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes one or more strings and, for each argument, puts
the last character that is a letter of each word in uppercase and the rest
in lowercase, then displays the result followed by a \n.

A word is a section of string delimited by spaces/tabs or the start/end of the
string. If a word has a single letter, it must be capitalized.

A letter is a character in the set [a-zA-Z]

If there are no parameters, display \n.

Examples:

$> ./rstr_capitalizer | cat -e
$
$> ./rstr_capitalizer "a FiRSt LiTTlE TESt" | cat -e
A firsT littlE tesT$
$> ./rstr_capitalizer "SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay, this is the last 1239809147801 but not    the least    t" | cat -e
seconD tesT A littlE biT   moaR compleX$
   but... thiS iS noT thaT compleX$
     okay, thiS iS thE lasT 1239809147801 buT noT    thE leasT    T$
$>*/
#include <unistd.h>

void rstr_capitalizer(char **argv)
{
    int i;
    int j;

    j = 0;
    while (argv[j] != NULL)
    {
        i = 0;
        while (argv[j][i] != '\0')
        {
            if (argv[j][i] >= 'A' && argv[j][i] <= 'Z')
                argv[j][i] = argv[j][i] + 32;
            i++;
        }
        j++;
    }
    j = 0;
    while (argv[j] != NULL)
    {
        i = 0;
        while (argv[j][i] != '\0')
        {
            if ((argv[j][i] == ' ' || argv[j][i] == '\t') && argv[j][i - 1] >= 'a' && argv[j][i - 1] <= 'z')
                argv[j][i - 1] = argv[j][i - 1] - 32;
            i++;
        }
        if (argv[j][i] == '\0' && argv[j][i - 1] >= 'a' && argv[j][i - 1] <= 'z')
            argv[j][i - 1] = argv[j][i - 1] - 32;
        j++;
    }
    j = 1;
    while (argv[j] != NULL)
    {
        i = 0;
        while (argv[j][i] != '\0')
        {
            write(1, &argv[j][i], 1);
            i++;
        }
        write(1, "\n", 1);
        j++;
    }
}

/*void rstr_capitalizer(char **argv) // 
{
    int i;
    int j;
    //int beforespace;

    //beforespace = argv[j][i] - 32;
    j = 0;
    while (argv[j] != NULL)
    {
        i = 0;
        while (argv[j][i] != '\0')
        {
            if (argv[j][i] >= 'A' && argv[j][i] <= 'Z')
                argv[j][i] = argv[j][i] + 32;
            if ((argv[j][i] == ' ' || argv[j][i] == '\t') && argv[j][i - 1] >= 'a' && argv[j][i - 1] <= 'z')
                argv[j][i - 1] = argv[j][i - 1] - 32;
            i++;
        }
        if (argv[j][i] == '\0' && argv[j][i - 1] >= 'a' && argv[j][i - 1] <= 'z')
            argv[j][i - 1] = argv[j][i - 1] - 32;
        j++;
    }
    j = 0;
    while (argv[j] != NULL)
    {
        i = 0;
        while (argv[j][i] != '\0')
        {
            write(1, &argv[j][i], 1);
            i++;
        }
        write(1, "\n", 1);
        j++;
    }
}
*/

// void rstr_capitalizer(char **argv) // código
// {
//     int i;
//     int j;

//     j = 1;
//     while (argv[j] != NULL)
//     {
//         i = 0;
//         while (argv[j][i] != '\0')
//         {
//             if (argv[j][i] >= 'A' && argv[j][i] <= 'Z')
//                 argv[j][i] = argv[j][i] + 32;
//             if (argv[j][i] >= 'a' && argv[j][i] <= 'z' && (argv[j][i + 1] == ' ' || argv[j][i + 1] == '\t' || argv[j][i + 1] == '\0') )
//                 argv[j][i] = argv[j][i] - 32;
//             write(1, &argv[j][i], 1);
//             i++;
//         }
//         write(1, "\n", 1);
//         j++;
//     }
// }

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        write(1, "\n", 1);
        return (1);
    }
    rstr_capitalizer(argv);
}