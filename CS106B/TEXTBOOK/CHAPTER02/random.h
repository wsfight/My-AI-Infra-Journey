/**
 * File:random.h
 * -------------
 * 这个文件是为了生成一个伪随机数
 */
#ifndef _random_h
#define _random_h
// 生成一个区间[low,high]之间的随机整数
int randomInteger(int low, int high);
// 生成一个区间[low,high)之间的随机实数
double randomReal(double low, double high);
// 被用来模拟特定概率的随机事件,并且该概率可以被设定.randomChance(0.75)将以0.75的概率返回真值
/**
 * string filpCoin(){
 *  if(randomChance(0.5)){
 *      // 已0.5为概率来返回真值
 *      return "正面";
 *  }
 *  else:
 *      return "反面";
 * }
 */
bool randomChance(double p);
void initRandomSeed();

#endif