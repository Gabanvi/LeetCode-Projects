#include <stdio.h>

int romanToInt(char *s)
{
    // to convert we add the numbers
    int total = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        // convert the current number into int
        int current_letter = 0;
        int next_letter = 0;

        switch (s[i])
        {
        case 'I':
            current_letter = 1;
            break;
        case 'V':
            current_letter = 5;
            break;
        case 'X':
            current_letter = 10;
            break;
        case 'L':
            current_letter = 50;
            break;
        case 'C':
            current_letter = 100;
            break;
        case 'D':
            current_letter = 500;
            break;
        case 'M':
            current_letter = 1000;
            break;
        }

        // convert next number into int
        // need to know the next number to see if we add or subtract the current letter's value (for cases like IV)

        if (s[i + 1] != '\0')
        {
            switch (s[i + 1])
            {
            case 'I':
                next_letter = 1;
                break;
            case 'V':
                next_letter = 5;
                break;
            case 'X':
                next_letter = 10;
                break;
            case 'L':
                next_letter = 50;
                break;
            case 'C':
                next_letter = 100;
                break;
            case 'D':
                next_letter = 500;
                break;
            case 'M':
                next_letter = 1000;
                break;
            }
        }

        if (next_letter > current_letter)
        {
            total -= current_letter;
        }
        else
        {
            total += current_letter;
        }
    }
    return total;
}

int main()
{
    char s1[] = "III";
    char s2[] = "LVIII";
    char s3[]= "MCMXCIV";

    printf("III is %d\n", romanToInt(s1));
     printf("LVIII is %d\n", romanToInt(s2));
}