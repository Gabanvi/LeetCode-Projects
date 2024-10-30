/*
 Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdlib.h>
#include <stdio.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) 
{
    int* result = (int*)malloc(2 * sizeof(int));
    
    //Loop to isolate each number one by one
    for (int i = 0; i < numsSize - 1; i++)
    { 
        //Loop to add the isolated number to each number in the array
        for (int j = i + 1; j < numsSize; j++)
        {
         // if the current combo adds up to the target, we fill in the result array with these 2 numbers
            if (nums[i] + nums[j] == target)
            {
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }
    *returnSize = 0; 
    return (0);
}

//int main () not to be included in the leetcode solution submission
int main ()
{
    int nums[] = {2, 7, 11, 15}; // Example 
    int numsSize = sizeof(nums) / sizeof(nums[0]); //Number of element = Tot size of array in bytes / size of one element in bytes 
    int target = 9; // Example target
    int returnSize;
    
    
    int* result = twoSum(nums, numsSize, target, &returnSize);
    
    // If we find a result
    if (result != NULL)
    {
        
        printf("Numbers that add up to %d: [%d, %d]\n", target, result[0], result[1]);
    }
    else
    {
        printf("No two numbers add up to the target.\n");
    }
    
    free(result);
    
    return 0;
}