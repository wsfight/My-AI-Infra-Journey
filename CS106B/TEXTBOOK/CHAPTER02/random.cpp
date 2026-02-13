#include <iostream>
#include <random>
#include <ctime>
#include <cmath>
#include "random.h"

int randomInteger(int low, int high)
{
    initRandomSeed();
    // 1.转成[0-1)
    double precentRandom = rand() / (double(RAND_MAX) + 1);
    // 2.开始量化
    double randomInt = floor(precentRandom * (double(high) - low + 1));
    return int(randomInt);
}
double randomReal(double low, double high)
{
    initRandomSeed();
    double precentRandom = rand() / (double(RAND_MAX) + 1);
    double randomR = low + precentRandom * (high - low);
    return randomR;
}
bool randomChance(double p)
{
    return randomReal(0, 1.0) < p;
}
void initRandomSeed()
{
    static bool initialed = false;
    if (!initialed)
    {
        srand(int(time(NULL)));
        initialed = true;
    }
}