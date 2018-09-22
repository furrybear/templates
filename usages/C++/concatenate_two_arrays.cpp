/*******************************************
Target: Concatenate 2 arrays
Author: furrybear<fbcll@outlook.com>
********************************************/
#include <algorithm>
#include <iostream>

using namespace std;

int main(int argc, char const* argv[])
{
    int a1[]{ 2, 6, 4, 3 };
    int a2[]{ 7, 3, 8, 1, 2 };
    auto a1_len = sizeof(a1) / sizeof(int);
    auto a2_len = sizeof(a2) / sizeof(int);
    sort(a1, a1 + a1_len);
    sort(a2, a2 + a2_len);

    cout << "a1 sorted:" << endl;
    for_each(a1, a1 + a1_len, [](auto i) { cout << i << " "; });
    cout << endl;
    cout << "a2 sorted:" << endl;
    for_each(a2, a2 + a2_len, [](auto i) { cout << i << " "; });
    cout << endl;

    int a3[a1_len + a2_len];
    auto a3_len = sizeof(a3) / sizeof(int);
    copy(a1, a1 + a1_len, a3);
    copy(a2, a2 + a2_len, a3 + a1_len);
    cout << "a3=a1+a2:" << endl;
    for_each(a3, a3 + a3_len, [](auto i) { cout << i << " "; });
    cout << endl;
}
