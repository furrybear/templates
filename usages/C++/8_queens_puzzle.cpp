/*******************************************
Target: 8 queens puzzle.
Author: furrybear<fbcll@outlook.com>
Remark: Use backtracking.
Reference: https://www.cnblogs.com/bigmoyan/p/4521683.html
********************************************/
#include <cmath>
#include <iostream>
using namespace std;

//八皇后问题，所以n是8
int n = 8;
//摆法计数器
int total = 0;
//皇后位置数组，下标是行数，值是列数
int* c = new int(n);

//判断函数，检查该行皇后放置是否合法
bool is_ok(int row)
{
    //检查前面所有行皇后的位置暗示的row行不能放置的位置
    for (int j = 0; j != row; j++) {
        //row行皇后不能放和该行皇后同一列
        //通过row行皇后和该行皇后直线的斜率不能为1
        //通过row行皇后和该行皇后直线的斜率不能为-1
        if (c[row] == c[j] || row - c[row] == j - c[j] || row + c[row] == j + c[j])
            return false;
    }
    return true;
}

//递归函数，参数的意思是尝试在row行放皇后
void recursion(int row)
{
    //如果row==8，说明放完了，摆法计数器total加一
    if (row == n)
        total++;
    //否则，遍历该行八个位置，查看是否可以继续放
    else
        for (int col = 0; col != n; col++) {
            //设置一下位置数组，该行放在col列
            c[row] = col;
            //检查是否合法，如果合法，继续放下一行
            if (is_ok(row))
                recursion(row + 1);
        }
}

int main()
{
    //从0行开始放
    recursion(0);
    cout << total << endl;
    return 0;
}