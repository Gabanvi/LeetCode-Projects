#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *addBinary(char *a, char *b)
{
    int len_a = strlen(a);
    int len_b = strlen(b);

    int max_len; // result lenght will be equal to the longest string plus the carry over if there is one

    if (len_a > len_b)
    {
        max_len = len_a;
    }
    else
    {
        max_len = len_b;
    }

    char *result = (char *)malloc(max_len + 2); // plus 2 to accomodate the carry over and the null oprator

    int index_a = len_a - 1;
    int index_b = len_b - 1;
    int index_result = 0;
    int carry_over = 0;

    // so the addition but the result will be in reverse at first
    while (index_a >= 0 || index_b >= 0 || carry_over != 0)
    {
        int digit_a = 0;
        int digit_b = 0;

        if (index_a >= 0)
        {
            digit_a = a[index_a] - '0'; // convert char to int
        }
        if (index_b >= 0)
        {
            digit_b = b[index_b] - '0'; // convert char to int
        }

        // addition
        int sum = digit_a + digit_b + carry_over; // add the current digits plus any carry over from previous addition

        result[index_result++] = (sum % 2) + '0'; // finding the remainder so to have 1 or 0 and +'0' to convert to char
        carry_over = sum / 2;                     // divide by 2 to determine if there’s a carry for the next iteration.

        index_a--;
        index_b--;
    }

    result[index_result] = '\0'; // add a null terminator to the string

    // Reverse the result to get the correct binary order

    int length_result = index_result;

    // swap the first with last, then seconde with second last etc ..
    // runs until the middle of the string so we dont undo revesals already done
    for (int i = 0; i < length_result / 2; i++)
    {
        char temp = result[i];

        result[i] = result[length_result - 1 - i];
        result[length_result - 1 - i] = temp;
    }
    return result;
}

int main(int argc, char *argv[])
{

    // check if we have the 2 strings given as arguments

    if (argc != 3)
    {
        printf("Usage: %s <binary string 1> <binary string 2>\n", argv[0]);
        return 1;
    }

    // Input the 2 strings as command line arguments

    char *a = argv[1];
    char *b = argv[2];

    char *result = addBinary(a, b);
    if (result != NULL)
    {
        printf("Result: %s\n", result);
        free(result); // Free the allocated memory
    }
    return 0;
}