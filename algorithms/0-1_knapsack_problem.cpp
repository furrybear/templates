/*******************************************
Problem: 0-1 knapsack problem.
Author: furrybear<bearcubhaha@gmail.com>
Input Sample：
4
20 20
50 30
100 60
5 3

Output Sample：
94
********************************************/
#include <array>
#include <iostream>
#include <vector>
using namespace std;

array<array<int, 121>, 2> dp_cache; //dp_cache[i-th thing][volume used], its value implies weight
vector<int> t1; //Every volume
vector<int> s1; //Every weight

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
    }

    for (n = 1; n <= N; n++) { //n implies n-th thing
        int iBase = !(n % 2);
        int iToCalculate = n % 2;
        for (int t = 0; t <= 120; t++) {
            int tmp = 0;
            tmp = max(dp_cache[iBase][t], tmp);
            if (t >= t1[n - 1])
                tmp = max(dp_cache[iBase][t - t1[n - 1]] + s1[n - 1], tmp);
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