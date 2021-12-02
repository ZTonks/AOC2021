#include<stdio.h>
#include<direction.h>

direction getDirection(char* inst)
{
    switch (*inst)
    {
        case 'u':
            return UP;
        case 'd':
            return DOWN;
        case 'f':
            return FORWARD;
        default:
            printf("UNRECOGNIZED CHARACTER %s PARSED", *inst);
            return ERR;
    }
}

int getDistance(char* inst)
{
    char* ptr = inst;

    while (*ptr++ != '\n') {
    }

    return *(ptr - 2) - '0';
}
