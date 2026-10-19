#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int random_num(int max, int min)
{
    return rand() % (max - min + 1) + min;
}