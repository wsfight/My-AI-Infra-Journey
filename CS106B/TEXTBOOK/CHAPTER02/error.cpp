/**
 * 一个简单的头文件用来演示接口与实现的分离
 *
 */
#include <iostream>
#include <string>
#include "error.h"

void error(std::string msg)
{
    std::cerr << msg << std::endl;
    exit(EXIT_FAILURE);
}