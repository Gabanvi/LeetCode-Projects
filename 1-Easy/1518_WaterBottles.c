#include <stdio.h>

int numWaterBottles(int numBottles, int numExchange)
{

    int drink = numBottles;
    int emptyBottles = numBottles;
    int newBottles;

    while (emptyBottles >= numExchange)
    {
        newBottles = emptyBottles / numExchange;
        drink += newBottles;
        emptyBottles = newBottles + (emptyBottles % numExchange);
    }
    return (drink);
}

int main()
{

    int numBottles = 15;
    int numExchange = 4;

    int result = numWaterBottles(numBottles, numExchange);

    printf("Expected = 19\n");
    printf("Result = %d\n", result);
}