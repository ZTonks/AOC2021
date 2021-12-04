#include<stdio.h>
#include<stdlib.h>
#include<binaryfuncs.h>

int main()
{
    char* originalFile = "/home/zak/AOC2021/day3/input";
    char byteStringsOrig[MAX_LINES][NUMCOLS] = { NULL };
    char byteStringsNext[MAX_LINES][NUMCOLS] = { NULL };

    readFileToArray(originalFile, byteStringsOrig);

    for (int i = 0; i < NUMCOLS; i++)
    {
        int commonBitOxy = getMostCommonBitForCol(
            byteStringsOrig,
            0);

        if (commonBitOxy < 0 || commonBitOxy > 1)
            return -1;

        writeArrayWithCommonBit(
            byteStringsOrig,
            byteStringsNext,
            commonBitOxy);
    }

    nullOutArray(byteStringsOrig);
    readFileToArray(originalFile, byteStringsOrig);
    
    for (int i = 0; i < NUMCOLS; i++)
    {
        int commonBitScrubber = getMostCommonBitForCol(
            byteStrings,
            i);

        if (commonBitScrubber < 0 || commonBitScrubber > 1)
            return -1;

        commonBitScrubber = !commonBitScrubber;

        writeFileWithCommonBit(
            originalFile,
            byteStrings,
            commonBitScrubber);
    }

    return 0;
}

