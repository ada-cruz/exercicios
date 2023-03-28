/*Assignment name  : repeat_alpha
Expected files   : repeat_alpha.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program called repeat_alpha that takes a string and display it
repeating each alphabetical character as many times as its alphabetical index,
followed by a newline.

'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...

Case remains unchanged.

If the number of arguments is not 1, just display a newline.

Examples:

$>./repeat_alpha "abc"
abbccc
$>./repeat_alpha "Alex." | cat -e
Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
$>./repeat_alpha 'abacadaba 42!' | cat -e
abbacccaddddabba 42!$
$>./repeat_alpha | cat -e
$
$>
$>./repeat_alpha "" | cat -e
$
$>*/

void repeat_alpha(char *str)
{
    // A = 65 a = 97
    // Z = 90 z = 122
    int i;
    int repeat_times;
    
    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 97 && str[i] <= 122)
        {
            repeat_times = 97;
            while(repeat_times <= str[i])
            {
                write(1, &str[i], 1);   
                repeat_times++;        
            }
        }
        else if (str[i] >= 65 && str[i] <= 90)
        {
            repeat_times = 65;
            while(repeat_times <= str[i])
            {
                write(1, &str[i], 1);   
                repeat_times++;        
            }
        }
        else
            write(1, &str[i], 1);
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return (0);
    repeat_alpha(argv[1]);
    write(1, "\n", 1);
}