/*******************************************
Problem: Matrix chain multiplication (or Matrix Chain Ordering Problem, MCOP).Given a sequence of matrices, the goal is to find the most efficient way to multiply these matrices.
Author: furrybear<fbcll@outlook.com>
********************************************/
#include <climits>
#include <cstdio>
#include <iostream>

using namespace std;

const int MAX_NUM = 100;

int dp[MAX_NUM][MAX_NUM];
bool hasCalculated[MAX_NUM][MAX_NUM]; // false
int a[MAX_NUM];

int f(int i, int j)
{
    // printf("Want dp[%d][%d]\n",i,j);
    if (hasCalculated[i][j] == true)
        return dp[i][j];
    int ret;
    if (j - i == 1) {
        ret = 0;
    } else if (j - i == 2) {
        ret = a[i] * a[i + 1] * a[i + 2];
    } else { // j-i>=2
        // Min
        ret = INT_MAX;
        for (int k = i + 1; k <= j - 1; ++k) {
            int tmp = f(i, k) + f(k, j) + a[i] * a[k] * a[j];
            if (tmp < ret)
                ret = tmp;
        }
    }
    // printf("dp[%d][%d]=%d\n",i,j,ret);
    hasCalculated[i][j] = true;
    dp[i][j] = ret;
    return ret;
}

int main()
{
    int N;
    cin >> N;
    for (int n = 0; n < N; ++n)
        cin >> a[n];

    cout << f(0, N - 1) << endl;

    return 0;
}