#ifndef _direction_h
#define _direction_h
#include <string>
enum Direction
{
    NORTH,
    EAST,
    SOUTH,
    WEST
};
// 就是从当前位置左转90度,比如北->西
Direction leftFrom(Direction dir);
// 就是从当前位置右转90度,比如北->东
Direction rightFrom(Direction dir);
// 打印出当前方向
std::string directionToString(Direction dir);
#endif