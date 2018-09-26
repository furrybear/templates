/*******************************************
Target: Use STL algorithm to achieve heaps
Author: furrybear<fbcll@outlook.com>
********************************************/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const* argv[])
{
    vector<int> v{ 15, 1, 12, 30, 20 };
    for_each(v.begin(), v.end(), [](const auto& i) { cout << i << " "; });
    cout << endl;

    //Make a heap
    make_heap(v.begin(), v.end()); //建堆
    for_each(v.begin(), v.end(), [](const auto& i) { cout << i << " "; });
    cout << endl;

    //Pop a node
    pop_heap(v.begin(), v.end());
    v.pop_back();
    for_each(v.begin(), v.end(), [](const auto& i) { cout << i << " "; });
    cout << endl;

    //Push a node
    v.push_back(99);
    push_heap(v.begin(), v.end());
    for_each(v.begin(), v.end(), [](const auto& i) { cout << i << " "; });
    cout << endl;

    //Pop all nodes, which is so-called heap sort
    sort_heap(v.begin(), v.end());
    for_each(v.begin(), v.end(), [](const auto& i) { cout << i << " "; });
    cout << endl;

    return 0;
}