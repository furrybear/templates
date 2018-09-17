#include <algorithm>
#include <iostream>
using namespace std;

class m {
public:
    m(const m& i)
    {
        cout << 1 << endl;
    }
    m(m& i)
    {
        cout << 2 << endl;
    }
    m() {}
};
void foo(m i)
{
}
int main(int argc, char const* argv[])
{
    m i;
    const auto i2 = i;
    const auto i3 = i;
    foo(i);
    foo(m());
    return 0;
}
