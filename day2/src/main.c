#include<stdio.h>
#include<stdlib.h>
#include<direction.h>
#include<wordfuncs.h>

int main()
{
    FILE* inputPtr = fopen("/home/zak/AOC2021/day2/input", "r");

    if (inputPtr == NULL)
        return -1;

    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    int xCoord = 0;
    int yCoord = 0;

    while ((read = getline(&line, &len, inputPtr)) != -1)
    {
        direction dir = getDirection(line);

        if (dir == ERR)
            return -1;

        int dist = getDistance(line);

        switch (dir)
        {
            case UP:
            case DOWN:
                yCoord += (dir == UP ? 1 : -1) * dist;
                break;
            case FORWARD:
                xCoord += dist;
                break;
        }
    }

    printf("End coords: X %d, Y %d\n", xCoord, yCoord);
    printf("End result of multiply: %d\n", xCoord * yCoord);

    return 0;
}
