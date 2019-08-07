#include <stdio.h>
#define maxArraySize 80

int main()
{
    int array[maxArraySize];
    int inputNumber, arrayIndex = 0;

    // user insert input
    while (scanf("%d", &inputNumber) != EOF)
    {
        array[arrayIndex] = inputNumber;
        arrayIndex++;
    }

    // after finish initilazing the arry
    int maxInputIndex = 0;

    for (int i = 0; i < arrayIndex; i++)
    {
        if (array[maxInputIndex] < array[i])
        {
            maxInputIndex = i;
        }
    }

    int row = arrayIndex;
    int col = array[maxInputIndex];

    // nested loop to print the output
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            if (array[j] < array[maxInputIndex])
            {
                printf(" ");
            }

            if (array[j] == array[maxInputIndex])
            {
                printf("#");
            }

            if (array[j] > array[maxInputIndex])
            {
                printf("#");
            }
        }

        printf("\n");
        array[maxInputIndex]--;
    }

    return 0;
}