// Jose Mathew
// Lab Assignment 6
// 2/23/24


#include <stdio.h>
#include <stdlib.h>


int search(int numbers[], int lowNum, int highNum, int value) 
{
    // If range is not valid:
    if (highNum < lowNum) 
    {
        return -1;
    }

    // To find middle index
    int midNum = lowNum + (highNum - lowNum) / 2;

    // If element is at the middle:
    if (numbers[midNum] == value) 
    {
        return midNum;
    }

    // If smaller than mid, then it can only be in left subarray
    if (numbers[midNum] > value) 
    {
        return search(numbers, lowNum, midNum - 1, value);
    }

    // Otherwise, it can only be in the right subarray
    return search(numbers, midNum + 1, highNum, value);
}


void printArray(int numbers[], int sz) 
{
    int i;
    printf("Number array : ");
    for (i = 0;i<sz;++i) 
    {
        printf("%d ",numbers[i]);
    }
    printf("\n");
}


int main(void) {
    int i, numInputs;
    float average;
    int value;
    int index;
    int* numArray = NULL;
    int countOfNums;
    FILE* inFile = fopen("input.txt","r");

    // Error message if file could not be opened
    if (inFile == NULL) 
    {
        printf("Could not open file\n");
        return 1;
    }

    fscanf(inFile, " %d\n", &numInputs);
    
    while (numInputs-- > 0) 
    {
        fscanf(inFile, " %d\n", &countOfNums);
        numArray = (int *) malloc(countOfNums * sizeof(int));
        average = 0;
        for (i = 0; i < countOfNums; i++) {
            fscanf(inFile," %d", &numArray[i]);
            average += numArray[i];
        }

        printArray(numArray, countOfNums);
        value = average / countOfNums;
        index = search(numArray, 0, countOfNums - 1, value);
        if (index >= 0) 
        {
            printf("Item %d exists in the number array at index %d!\n", value, index);
        } else 
        {
            printf("Item %d does not exist in the number array!\n", value);
        }

        free(numArray);
    }

    fclose(inFile);
}
