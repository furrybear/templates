//--------------------------------------
//Problem: Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 1 is the first ugly number.
//Target: Input n and find the n’th ugly number.
//Solution: Generate the ugly number sequence in memory. "i_2" is the index of the first element from left, whoes double value is greater than the last element. "value_2" is the double value. "i_3", "i_5", "value_3" and "value_5" have similar meaning. The next element pushed into the sequence is the minimum of "value_2", "value_3" and "value_5".
//Author: furrybear<bearcubhaha@gmail.com>
//--------------------------------------
#include <iostream>
#include <vector>

using namespace std;

template <typename Integer = int>
class ugly_number_sequence {
    vector<Integer> v; // Record ugly number sequence
    int i_2;
    Integer value_2;
    int i_3;
    Integer value_3;
    int i_5;
    Integer value_5;

public:
    ugly_number_sequence()
        : v(1, 1) // The first ugly number is 1
        , i_2(0)
        , value_2(2)
        , i_3(0)
        , value_3(3)
        , i_5(0)
        , value_5(5)
    {
    }
    int operator[](const int index) // index should not be less than than 0
    {
        if (index < v.size())
            return v[index];
        while (index >= v.size()) {
            int minimum = min(value_2, min(value_3, value_5));
            //Push the minimum of them to v.
            v.push_back(minimum);
            if (value_2 <= minimum) {
                i_2++;
                value_2 = v[i_2] * 2;
            }
            if (value_3 <= minimum) {
                i_3++;
                value_3 = v[i_3] * 3;
            }
            if (value_5 <= minimum) {
                i_5++;
                value_5 = v[i_5] * 5;
            }
            /*
            for (auto i : v) {
                cout << i << " ";
            }*/
            cout << endl;
        }
        return v.back();
    }
};
int main()
{
    int n;
    cin >> n;
    ugly_number_sequence<> u;
    cout << u[n - 1] << flush;
    return 0;
}