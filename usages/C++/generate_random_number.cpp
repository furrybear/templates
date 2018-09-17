/*******************************************
Target: How to generate random number with header random
Author: furrybear<fbcll@outlook.com>
********************************************/
#include <iostream>
#include <random>
using namespace std;

int main()
{
    //随机数引擎
    default_random_engine e;
    //随机浮点数分布类对象，范围为[0,1)
    uniform_real_distribution<double> rr(0.0, 1.0);
    for (int i = 0; i < 10; ++i)
        cout << rr(e) << endl;
    //随机非负整数分布类对象，范围为[0,9]
    uniform_int_distribution<unsigned int> ri(0, 9);
    for (int i = 0; i < 10; ++i)
        cout << ri(e) << endl;
    return 0;
}