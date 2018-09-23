/*******************************************
Problem: All permutation.
Author: furrybear<fbcll@outlook.com>
********************************************/
#include <algorithm>
#include <array>
#include <iostream>
using namespace std;

void perm(int arr[], unsigned int begin, unsigned int end)
{
    if (end == begin) { //一到递归的出口就输出数组，此数组为全排列
        for (unsigned int i = 0; i <= end; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    } else {
        for (unsigned int j = begin; j <= end; j++) {
            swap(arr[begin], arr[j]); //for循环将begin~end中的每个数放到begin位置中去
            perm(arr, begin + 1, end); //假设begin位置确定，那么对begin+1~end中的数继续递归
            swap(arr[begin], arr[j]); //换过去后再还原
        }
    }
}

int main()
{
    cout << "Output all permutation by STL algorithm." << endl;
    array<int, 3> a{ 1, 3, 2 };
    sort(a.begin(), a.end());
    cout << "The 3! possible permutations with 3 elements:\n";
    do {
        cout << a[0] << ' ' << a[1] << ' ' << a[2] << '\n';
    } while (next_permutation(a.begin(), a.end()));
    cout << "After loop:\n"
         << a[0] << ' ' << a[1] << ' ' << a[2] << '\n';

    cout << "Output all permutation by custom functions." << endl;
    int arr[] = { 1, 2, 3, 4 };
    perm(arr, 0, sizeof(arr) / sizeof(int) - 1);

    return 0;
}