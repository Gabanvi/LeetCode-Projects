#include <stdio.h>

long long minimumSteps(char *s)
{
    long long swaps = 0;
    int black = 0; //counts every black ball encountered
    int i = 0;

    while (s[i] != '\0')
    {
        if (s[i] == '1')
        {
            black++;
        }
       // If we encounter a '0', we add the number of '1's (black) seen so far to swaps
       // Because each '0' after a '1' will need to "swap places" with all previous '1's
        else if (s[i] == '0')
        {
            swaps += black;
        }
        i++;
    }

    return (swaps);
}

int main()
{
    char s1[] = "101";
    char s2[] = "100";
    char s3[] = "0111";

    printf("\n");
    printf("String to sort: %s\n", s1);
    printf("Expected: 1\n");
    printf("Output: %lld\n", minimumSteps(s1));
    printf("\n");

    printf("String to sort: %s\n", s2);
    printf("Expected: 2\n");
    printf("Output: %lld\n", minimumSteps(s2));
    printf("\n");

    printf("String to sort: %s\n", s3);
    printf("Expected: 0\n");
    printf("Output: %lld\n", minimumSteps(s3));
    printf("\n");

    return 0;
}