#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int randomNum(int max, int min)
{
    return rand() % (max - min + 1) + min;
}