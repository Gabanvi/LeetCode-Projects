#include <stdio.h>
#include <limits.h>

int myAtoi(char *s)
{
    int i = 0;
    int sign_value = 1;
    long result = 0;

    // whitespaces
    while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
    {
        i++;
    }

    // Signedness
    while (s[i] == 45 || s[i] == 43)
    {
        if (s[i] == 45)
            sign_value *= -1;
        i++;

        if (s[i] == '-' || s[i] == '+')
        {
            return 0;
        }
    }

    // Conversion
    while (s[i] >= '0' && s[i] <= '9')
    {
        result = result * 10 + (s[i] - '0');

        if (sign_value == 1 && result > INT_MAX)
            return INT_MAX;

        if (sign_value == -1 && -result < INT_MIN)
            return INT_MIN;

        i++;
    }
    return (result * sign_value);
}

int main()
{
    char s1[] = "1337c0d3";
    char s2[] = "-042";
    char s3[] = "words and 987";

    printf("Input = %s\n", s1);
    int result = myAtoi(s1);
    printf("Expected = 1337\n");
    printf("Result = %d\n", result);
    printf("\n");

    printf("Input = %s\n", s2);
    result = myAtoi(s2);
    printf("Expected = -42\n");
    printf("Result = %d\n", result);
    printf("\n");

    printf("Input = %s\n", s3);
    result = myAtoi(s3);
    printf("Expected = 0\n");
    printf("Result = %d\n", result);
    printf("\n");
}