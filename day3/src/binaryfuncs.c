#include<stdio.h>

int parseBit(char* inst, int position)
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
