#include<stdio.h>
#include<stdlib.h>
#include<binaryfuncs.h>

int main()
{
    FILE* inputPtr = fopen("/home/zak/AOC2021/day3/input", "r");

    if (inputPtr == NULL)
        return -1;

    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    int totals[NUMCOLS] = { 0 };
    int numLines = 0;
    int numCols = 0;

    while ((read = getline(&line, &len, inputPtr)) != -1)
    {
        for (int i = 0; i < NUMCOLS; i++)
        {
            int parsed = parseBit(line, i);

            if (parsed < 0 || parsed > 1)
                return -1;

            totals[i] += parsed;
        }

        numLines++;
    }

    printf("total number of lines: %d\n", numLines);

    int gamma = 0;
    int epsilon = 0;

    for (int i = 0; i < NUMCOLS; i++)
    {
        printf("number of bits in column %d: %d\n", i + 1, totals[i]);

        int fewerBits = 2 * totals[i] <= numLines;

        if (fewerBits)
            printf("claim is more zeroes for column %d\n", i);

        int exponent = NUMCOLS - i - 1;

        gamma += !fewerBits * (1 << exponent);
        epsilon += fewerBits * (1 << exponent);

        printf("gamma: %d, epsilon: %d\n", gamma, epsilon);
    }

    printf("multiplication of gamma and epsilon: %d\n", gamma * epsilon);

    return 0;
}

