#include <string.h>
#include <stdio.h>

int lengthOfLastWord(char *s)
{
    int last_length = 0;
    int i = strlen(s) - 1;

    // Skip trailing spaces at the end of the string
    while (i >= 0 && s[i] == ' ')
    {
        i--;
    }

    // Count the characters in the last word until a space is found or the beginning of string
    while (i >= 0 && s[i] != ' ')
    {
        last_length++;
        i--;
    }
    return (last_length);
}

int main()
{
    char s1[] = "Cat Dog Supercalifragilisticexpialidocious";
    char s2[] = "one two three   ";

    printf("Lenght of Supercalifragilisticexpialidocious: %d \n", lengthOfLastWord(s1));
    printf("Lenght of three: %d \n", lengthOfLastWord(s2));
}
