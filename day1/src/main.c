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

    int depth1 = INT_MAX;
    int depth2 = INT_MAX;
    int depth3 = INT_MAX;
    int lastSum = INT_MAX;
    int numTimesIncreased = 0;

    while ((read = getline(&line, &len, inputptr)) != -1)
    {
        depth1 = depth2;
        depth2 = depth3;
        depth3 = atoi(line);

        if (depth1 != INT_MAX && depth2 != INT_MAX)
        {
            int sum = depth1 + depth2 + depth3;

            numTimesIncreased += sum > lastSum;

            lastSum = sum;
        }
    }

    printf("%d\n", numTimesIncreased);

    return 0;
}
