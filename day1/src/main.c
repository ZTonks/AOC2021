#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int main()
{
    FILE* inputptr = fopen("/home/zak/AOC2021/day1/input", "r");

    if (inputptr == NULL)
        return -1;

    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    int lastDepth = INT_MAX;
    int numTimesIncreased = 0;

    while ((read = getline(&line, &len, inputptr)) != -1) {

        int depth = atoi(line);

        numTimesIncreased += depth > lastDepth;

        lastDepth = depth;
    }

    printf("%d\n", numTimesIncreased);

    return 0;
}
