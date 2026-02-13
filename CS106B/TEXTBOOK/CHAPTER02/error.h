/**
 * 一个简单的头文件用来演示接口与实现的分离
 */

#ifndef _error_h // 如果没有定义过,则往下走.防止多次编译
#define _error_h // 如果没定义过,则定义
#include <string>
void error(std::string msg);
#endif