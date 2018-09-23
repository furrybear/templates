/*******************************************
Problem: Custom split function for STL string.
Author: furrybear<fbcll@outlook.com>
********************************************/
#include <iostream>
#include <vector>
using namespace std;

vector<string> split(const string& s, const string& c)
{
    vector<string> v;
    string::size_type pos1, pos2;
    pos2 = s.find(c); //Right border of substring
    pos1 = 0; //Left border of substring
    while (pos2 != string::npos) {
        v.push_back(s.substr(pos1, pos2 - pos1));
        pos1 = pos2 + c.size();
        pos2 = s.find(c, pos1);
    }
    if (pos1 != s.length())
        v.push_back(s.substr(pos1));
    return v;
}

int main()
{
    string s = "miaomiaomiaohaha";
    string c = "i";
    auto vs = split(s, c);
    for (const auto& s : vs) {
        cout << s << endl;
    }
}