#include<stdio.h>
#include<unistd.h>

int readFileToArray(
    char* fileName,
    char** arr)
{
    FILE* inputPtr = fopen(fileName, "r");

    if (inputPtr == NULL)
        return -1;

    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    int arrayIndex = 0;

    while ((read = getline(&line, &len, inputPtr)) != -1)
    {
        arr[arrayIndex++];
    }

    return fclose(inputPtr);
}

int nullOutArray(
    char** arr)
{
    int arrayIndex = 0;

    while (arrayIndex < MAX_LINES)
    {
        arr[arrayIndex++] = NULL;
    }
}

int getNumBitsInColForFile(
    char* fileName,
    int position)
{
    int total = 0;

    FILE* inputPtr = fopen(fileName, "r");

    if (inputPtr == NULL)
        return -1;

    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, inputPtr)) != -1)
    {
        int parsed = parseBit(line, position);

        if (parsed < 0 || parsed > 1)
            return -1;

        total += parsed;
    }

    fclose(inputPtr);

    return total;
}

int getNumBitsInColForArray(
    char** arr,
    int position)
{
    int total = 0;
    int index = 0;

    while (arr[index])
    {
        int parsed = parseBit(arr[index++], position);

        if (parsed < 0 || parsed > 1)
            return -1;

        total += parsed;
    }

    return total;
}

int writeArrayWithCommonBitFromFile(
    char* originalFile,
    char** byteStrings, 
    int commonBit)
{
    FILE* originalFilePtr = fopen(originalFile, "r");

    if (originalFilePtr == NULL)
        return -1;

    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    int arrIndex = 0;
    int numLines = 0;

    while ((read = getline(&line, &len, inputPtr)) != -1)
    {
        if (parseBit(line, 0) == commonBit)
            byteStrings[arrIndex++] = line;

        numLines++;
    }

    while (arrIndex < numLines)
    {
        byteStrings[arrIndex++] = NULL;
    }
}

int writeArrayWithCommonBitFromArray(
    char** originalArr,
    char** byteStrings, 
    int commonBit)
{
    int origIndex = 0;
    int arrIndex = 0;

    while (originalArr[origIndex])
    {
        if (parseBit(originalArr[origIndex], 0) == commonBit)
            byteStrings[arrIndex++] = line;

        origIndex++;
    }

    while (arrIndex < 1000)
    {
        byteStrings[arrIndex++] = NULL;
    }
}

int parseBit(
    char* inst,
    int position)
{
    if (position > NUMCOLS - 1)
    {
        printf("BAD POSITION %d PASSED\n", position);
        return -1;
    }

    char* ptr = inst;
    int i = 0;

    while (*ptr++ != '\n' && i++ < position) {
    }

    return *(ptr - 1) - '0';
}
