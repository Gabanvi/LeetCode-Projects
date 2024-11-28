#include <limits.h> // For INT_MAX and INT_MIN
#include <stdbool.h>
#include <stdio.h>

bool checkOverflow(int reversed, int digit)
{

    // see if reversed exceeds int MAX
    if (reversed > INT_MAX / 10 || (reversed == INT_MAX / 10 && digit > 7))
    {
        return (true);
    }

    if (reversed < INT_MIN / 10 || (reversed == INT_MIN / 10 && digit < -8))
    {
        return (true);
    }
    return (false);
}

int reverse(int x)
{
    int reversed = 0;
    int digit;

    while (x != 0)
    {
        // for any integer %10 gives the last digit of that number
        // i.e. 123 / 10 results in 12 = quotient and 3 = remainder.
        digit = x % 10;

        // check if there would be an overflow
        if (checkOverflow(reversed, digit))
        {
            return 0; // if yes, return 0
        }

        // add the digit to reversed number
        // multiplying reversed by 10, shift its digits one place to the left and add new digit
        reversed = reversed * 10 + digit;

        // remove the last digit from the number to update x for next iteration
        // in integer division, the fractional part is discarded
        x /= 10;
    }

    return (reversed);
}

int main() {
    while (true) {
        int number;
        char choice;

        // Prompt the user for number to reverse
        printf("\nEnter a number to reverse (within [-2,147,483,648, 2,147,483,647]): ");
        if (scanf("%d", &number) != 1) 
        {
            // Tell them they need to do better...
            printf("Invalid input honey. Please enter a valid integer.\n");
            while (getchar() != '\n'); // Clear invalid input
            continue;
        }

        // Reverse the number
        int reversedNumber = reverse(number);

        // Display the result
        if (reversedNumber == 0 && number != 0) {
            printf("Reversing this number caused overflow. Result: 0\n");
        } else {
            printf("Reversed number: %d\n", reversedNumber);
        }

        // Ask if user wants to reverse another number of leave
        printf("\nDo you want to reverse another number? (y/n): ");
        getchar(); // Consume the newline character left by scanf
        scanf("%c", &choice);

        if (choice == 'n' || choice == 'N') //if yes then then loop continues and asks for new number
        {
            printf("Goodbye <3 \n");
            break;
        }
    }

    return 0;
}
