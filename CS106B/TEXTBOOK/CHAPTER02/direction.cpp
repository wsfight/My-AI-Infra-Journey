#include <iostream>
#include <string>
#include "direction.h"
Direction leftFrom(Direction dir)
{
    return Direction((dir + 3) % 4);
}
Direction rightFrom(Direction dir)
{
    return Direction((dir + 1) % 4);
}
std::string directionToString(Direction dir)
{
    std::string s;
    switch (dir)
    {
    case 0:
        s = "North";
        break;
    case 1:
        s = "East";
        break;
    case 2:
        s = "South";
        break;
    case 3:
        s = "West";
        break;
    default:
        s = "???";
        break;
    }
    return s;
}