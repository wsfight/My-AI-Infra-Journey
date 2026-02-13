#include <iostream>
#include <vector>
using namespace std;
int binarySearch(int key, vector<int> &vec, int p1, int p2);
int binarySearch2(int key, vector<int> &vec, int p1, int p2);
bool isEven(unsigned int n);
bool isOdd(unsigned int n);
int main()
{
    vector<int> vec{1, 2, 3, 4, 5};
    cout << binarySearch(2, vec, 0, 4) << endl;  // 2
    cout << binarySearch2(2, vec, 0, 4) << endl; // 2
    cout << bool(isEven(10)) << endl;
    return 0;
}
int binarySearch(int key, vector<int> &vec, int p1, int p2)
{
    if (p1 > p2)
        return -1; // 表明没有找到
    while (p1 <= p2)
    {
        int mid = (p1 + p2) / 2;
        if (vec[mid] == key)
            return mid;
        else if (vec[mid] < key)
            p1 = mid + 1;
        else
            p2 = mid - 1;
    }
    return -1;
}
int binarySearch2(int key, vector<int> &vec, int p1, int p2)
{
    if (p1 > p2)
        return -1;
    int mid = (p1 + p2) / 2;
    if (vec[mid] == key)
        return mid;
    else if (vec[mid] < key)
    {
        return binarySearch2(key, vec, mid + 1, p2);
    }
    else
    {
        return binarySearch2(key, vec, p1, mid - 1);
    }
}
bool isEven(unsigned int n)
{
    if (n == 0)
    {
        return true;
    }
    else
    {
        return isOdd(n - 1);
    }
}
bool isOdd(unsigned int n)
{
    return !isEven(n);
}