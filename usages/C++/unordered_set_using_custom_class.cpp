#include <iostream>
#include <unordered_set>
using namespace std;

class Bear{
public:
    int a;
    Bear( int a ):a( a ){};
};

namespace std {
    template<>
    class hash<Bear *>{
    public:
        size_t operator()( const Bear *b ) const
        {
            return hash<int>()(b->a);
        }
    };
    template<>
    class equal_to<Bear *>{
    public:
        size_t operator()( const Bear *b1, const Bear *b2 ) const
        {
            return b1->a == b2->a;
        }
    };
};

int main()
{
    cout << "Hello World!" << endl;
    unordered_set<Bear *> s;
    s.insert( new Bear(0) );
    s.insert( new Bear(1) );
    s.insert( new Bear(2) );
    for( const Bear *b : s )
    {
        cout << b->a << endl;
    }
    cout << s.size() << endl;
    return 0;
}
