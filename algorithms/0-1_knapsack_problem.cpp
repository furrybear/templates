#include <array>
#include <iostream>
#include <vector>
using namespace std;
/*
输入：
4
20 20 100 60
50 30 80 55
100 60 110 88
5 3 10 6
输出：
94
*/
array<array<int, 121>, 2> dp_cache; //dp_cache[第i个题目][已经使用的时间]，值为分数
vector<int> t1; //时间
vector<int> s1; //分数
vector<int> t2; //时间
vector<int> s2; //分数

int main()
{
    int N;
    cin >> N;
    int n = N;
    cout << dp_cache[1][1] << endl;

    while (n--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        t1.push_back(a);
        s1.push_back(b);
        t2.push_back(c);
        s2.push_back(d);
    }

    for (n = 1; n <= N; n++) { //n表示当前要处理第几道题
        int iBase = !(n % 2);
        int iToCalculate = n % 2;
        for (int t = 0; t <= 120; t++) {
            int tmp = 0;
            tmp = max(dp_cache[iBase][t], tmp);
            if (t >= t1[n - 1])
                tmp = max(dp_cache[iBase][t - t1[n - 1]] + s1[n - 1], tmp);
            if (t >= t2[n - 1])
                tmp = max(dp_cache[iBase][t - t2[n - 1]] + s2[n - 1], tmp);
            dp_cache[iToCalculate][t] = tmp;
        }
        for (int i = 0; i < dp_cache[iToCalculate].size(); i++) {
            printf("%d ", dp_cache[iToCalculate][i]);
        }
        cout << endl;
    }
    cout << dp_cache[N % 2][120] << endl;
    return 0;
}