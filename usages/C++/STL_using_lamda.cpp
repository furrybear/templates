/*******************************************
Target: Use STL container and algorithm with lamda for custom function
Author: furrybear<fbcll@outlook.com>
********************************************/
#include <algorithm>
#include <iostream>
#include <unordered_set>

using namespace std;

class my_class {
public:
    int id;
    int num;
};

int main(int argc, char const* argv[])
{
    auto my_class_hash = [](const my_class& e) {
        return hash<int>()(e.id);
    };
    auto my_class_equal = [](const my_class& le, const my_class& re) {
        return le.id == re.id;
    };
    unordered_set<
        my_class,
        decltype(my_class_hash),
        decltype(my_class_equal)>
        s(
            0, //set will override the bucket count to proper value
            my_class_hash,
            my_class_equal);
    s.insert(my_class{ 0, 10 });
    s.insert(my_class{ 1, 30 });
    s.insert(my_class{ 0, 20 });
    s.insert(my_class{ 2, 40 });
    cout << "Set after inserting:" << endl;
    for (auto e : s) {
        cout << "Value of ID " << e.id << ": " << e.num << endl;
    }
    cout << "Size of set: " << s.size() << endl;

    vector<my_class> v;
    v.push_back(my_class{ 2, 10 });
    v.push_back(my_class{ 3, 10 });
    v.push_back(my_class{ 0, 10 });
    v.push_back(my_class{ 1, 10 });
    sort(v.begin(), v.end(), [](const my_class& le, const my_class& re) {
        return le.id > re.id;
    });
    cout << "Vector after sorting:" << endl;
    for (const auto& e : v) {
        cout << "Value of ID " << e.id << ": " << e.num << endl;
    }
    return 0;
}
