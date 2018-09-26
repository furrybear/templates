/*******************************************
Target: Use STL priority_queue to achieve heaps
Author: furrybear<fbcll@outlook.com>
********************************************/
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int main(int argc, char const* argv[])
{
    priority_queue<int> heap;

    for (int n : { 15, 1, 12, 30, 20 })
        heap.push(n);

    while (!heap.empty()) {
        cout << heap.top() << " ";
        heap.pop();
    }
    cout << endl;

    return 0;
}