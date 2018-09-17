/*******************************************
Problem: KMP algorithm
Author: furrybear<fbcll@outlook.com>

Input Sample:
BBC ABCDAB ABCDABCDABDE
ABCDABD

Output Sample:
True
********************************************/
#include <iostream>
#include <vector>

using namespace std;

class KMP {
    vector<int> partial_match_table;
    bool result;

public:
    KMP(const string& searched, const string& pattern)
        : partial_match_table(pattern.size(), 0)
        , result(false)
    {
        //Construct the patial match table
        auto partial_match = partial_match_table.rbegin();
        //Traverse every prefix of the pattern including the pattern itself
        for (auto it_patial_end = pattern.end(); it_patial_end != pattern.begin(); it_patial_end--) {
            //Compare the prefix and suffix of "the prefix of the pattern (string(pattern.begin(), it_pattern_end))" from longest to the shotest. If the prefix is same as the suffix, assign the corresponding element of partial_match_table to the length of the prefix, and then break.
            for (auto it_prefix_end = it_patial_end - 1, it_suffix_begin = pattern.begin() + 1;
                 it_prefix_end != pattern.begin();
                 it_prefix_end--, it_suffix_begin++) {
                //cout << string(pattern.begin(), it_prefix_end) << " "
                //     << string(it_suffix_begin, it_patial_end) << endl;
                if (string(pattern.begin(), it_prefix_end) == string(it_suffix_begin, it_patial_end)) {
                    *partial_match = distance(pattern.begin(), it_prefix_end);
                    break;
                }
            }
            partial_match++;
        }
        /*
        for (auto i : partial_match_table) {
            cout << i << endl;
        }*/

        //Start searching
        auto s_it = searched.begin(); //Position to be checked in the string to be searched
        auto p_it = pattern.begin(); //Position to be checked in the pattern string
        while (s_it != searched.end()) {
            if (*s_it == *p_it) {
                //Continue checking
                //cout << "Matching" << endl;
                s_it++;
                p_it++;
            } else {
                if (p_it == pattern.begin()) {
                    //Check next char in the string to be searched
                    //cout << "Not matching" << endl;
                    s_it++;
                } else {
                    //p_it should step back
                    cout << distance(pattern.begin(), p_it) - 1 << endl;
                    //Calculating step count does not consider char which is checking.
                    int len_checked = distance(pattern.begin(), p_it);
                    p_it -= len_checked - partial_match_table.at(len_checked - 1);
                    p_it = max(p_it, pattern.begin());
                }
            }
            //Finishing checking the pattern means the string contains the pattern. It's the circulatory termination condition.
            if (p_it == pattern.end()) {
                result = true;
                break;
            }
        }
    }
    operator bool()
    {
        return result;
    }
};

int main()
{
    //Get string to be seached and string as the pattern
    string searched, pattern;
    getline(cin, searched);
    getline(cin, pattern);

    cout << "KMP result:" << endl;
    cout << (KMP(searched, pattern) ? "True" : "False") << endl;
    cout << "STL function result:" << endl;
    cout << (searched.find(pattern) != string::npos ? "True" : "False") << endl;
    return 0;
}