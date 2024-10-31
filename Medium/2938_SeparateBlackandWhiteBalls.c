#include <stdio.h>

long long minimumSteps(char *s)
{
    long long swaps = 0;
    int black = 0;
    int i = 0;

    while (s[i] != '\0')
    {
        if (s[i] == '1')
        {
            black++;
        }
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