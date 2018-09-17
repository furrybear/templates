/*******************************************
Problem: Calculate combination number in dynamic programming
Author: furrybear<fbcll@outlook.com>
********************************************/
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

//动态规划计算组合数
class Combinations { //组合数顶多大概计算到15C30
    vector<vector<int>> combinations; //[r][n]

public:
    Combinations(int max_r, int max_n)
        : combinations(max_r + 1)
    {
        combinations[0].assign(max_n + 1, 1);
        for (int i = 1; i <= max_r; ++i) {
            combinations[i].assign(max_n + 1, 0);
        }
    }
    int get(int r, int n)
    { //计算rCn
        int& target = combinations.at(r).at(n); //会检查下标
        if (target == 0 && n >= r)
            target = get(r, n - 1) + get(r - 1, n - 1); // rCn=rC(n-1)+(r-1)C(n-1)
        return target;
    }
};

int main()
{
    clock_t start = clock();
    int n = 100;
    int r = 100;
    Combinations c(r, n);

    cout << c.get(3, 5) << endl;
    printf("%ldms", clock() - start);
    return 0;
}
