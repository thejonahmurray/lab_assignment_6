#include <stdio.h>
#include <stdlib.h>

int search(int numbers[], int low, int high, int value) {
    if (low > high) {
        return -1;
    }
    //Finding middle value at array to go either up or down
    int middle = low + (high - low) / 2;

    if (numbers[middle] == value) {
        return middle;
    //Recursion
    } else if (value < numbers[middle]) {
        return search(numbers, low, middle - 1, value);
    } else {
        return search(numbers, middle + 1, high, value);
    }
}

void printArray(int numbers[], int sz) {
    int i;
    //Prints all numbers in the array
    printf("Number array : ");
    for (i = 0; i < sz; ++i) {
        printf("%d ", numbers[i]);
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
    //Open file
    FILE* inFile = fopen("input.txt", "r");

    fscanf(inFile, "%d", &numInputs);

    while (numInputs-- > 0) {
        fscanf(inFile, "%d", &countOfNums);
        //Memory allocation
        numArray = (int*)malloc(countOfNums * sizeof(int));
        average = 0;
        for (i = 0; i < countOfNums; i++) {
            fscanf(inFile, "%d", &value);
            numArray[i] = value;
            average += numArray[i];
        }

        printArray(numArray, countOfNums);
        value = average / countOfNums;
        index = search(numArray, 0, countOfNums - 1, value);
        if (index >= 0) {
            printf("Item %d exists in the number array at index %d!\n", value, index);
        } else {
            printf("Item %d does not exist in the number array!\n", value);
        }

        free(numArray);
    }

    fclose(inFile);
    return 0;
}
