/*******************************************
Target: Use STL container and algorithm with explicit template specialization for more custom function
Author: furrybear<bearcubhaha@gmail.com>
********************************************/
#include <algorithm>
#include <iostream>
#include <unordered_set>
//#include <vector>
using namespace std;

class my_class {
public:
    int id;
    int num;
};

// Definition of hash and comparison functor of my_class, which is so-called Explicit Template Specialization
namespace std {
//unordered_set needs to know how to hash my_class and how to
template <>
struct hash<my_class> {
    size_t operator()(const my_class& e) const
    {
        return hash<int>()(e.id);
    }
};
template <>
struct equal_to<my_class> {
    bool operator()(const my_class& le, const my_class& re) const
    {
        return le.id == re.id;
    }
};
/*
template <>
struct comp<my_class> {
    bool operator()(const my_class& le, const my_class& re) const
    {
        return le.id < re.id;
    }
};
*/
};

int main()
{
    unordered_set<my_class> s;
    s.insert(my_class{ 0, 10 });
    s.insert(my_class{ 1, 30 });
    s.insert(my_class{ 0, 20 });
    s.insert(my_class{ 2, 40 });
    for (auto e : s) {
        cout << "Value of ID " << e.id << ": " << e.num << endl;
    }
    cout << "Size of set: " << s.size() << endl;
    /*
    vector<my_class> v;
    v.push_back(my_class{ 2, 10 });
    v.push_back(my_class{ 3, 10 });
    v.push_back(my_class{ 0, 10 });
    v.push_back(my_class{ 1, 10 });
    sort(v.begin(), v.end());
    cout << "Vector after sorting:" << endl;
    for (const auto& e : v) {
        cout << "Value of ID " << e.id << ": " << e.num << endl;
    }*/
    return 0;
}
