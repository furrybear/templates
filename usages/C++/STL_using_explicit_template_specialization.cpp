/*******************************************
Target: Use STL container with explicit template specialization for more custom function
Author: furrybear<fbcll@outlook.com>
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
    return 0;
}
