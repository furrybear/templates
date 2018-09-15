/*******************************************
Problem: Quick Sort
Author: furrybear<bearcubhaha@gmail.com>
********************************************/
#include <iostream>
using namespace std;

void dumpArr(int* const a, const int len)
{
    for (int i = 0; i < len; i++) {
        printf("%d ", a[i]);
    }
    cout << endl;
}
//返回：iMid，就是基准的下标
int partition(int* const a, const int len)
{
    int& pivot = a[len - 1]; //基准的值，选取最后一个元素为基准
    int iTailLeft = 0; //放入左侧数组（比基准的值小）的下一个位置
    for (int i = 0; i < len - 1; i++) {
        if (a[i] <= pivot) {
            swap(a[iTailLeft], a[i]);
            iTailLeft++;
        }
    }
    swap(a[iTailLeft], pivot);
    return iTailLeft;
}

void quickSort(int* const a, const int len)
{
    //    dumpArr( a , len );
    if (len <= 1)
        return;
    const int iMid = partition(a, len);
    //   cout << iMid << endl;
    //   dumpArr( a , len );
    //   return;
    int* const left = a;
    int* const right = a + iMid + 1;
    const int lenLeft = iMid; //0~len-1
    const int lenRight = len - iMid - 1; //0~len-1
    quickSort(left, lenLeft);
    quickSort(right, lenRight);
}

int main()
{
    int a[] = { 12, 43, 21, 1, 2, 3, 7, 3, 8, 2, 4, 5 };
    int len = sizeof(a) / sizeof(int);
    dumpArr(a, len);
    quickSort(a, len);
    dumpArr(a, len);
    return 0;
}
