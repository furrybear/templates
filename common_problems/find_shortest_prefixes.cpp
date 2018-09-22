/*******************************************
Problem: Find for each word the shortest prefix that uniquely identifies the word it represents.
Author: furrybear<fbcll@outlook.com>
********************************************/
#include <iostream>
#include <memory>
#include <numeric>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

class trie {
protected:
    struct node {
        bool is_end;
        int cnt;
        unordered_map<char, shared_ptr<node>> next;
        node()
            : is_end{ false }
            , cnt{ 0 }
        {
        }
    };
    shared_ptr<node> root;

public:
    trie()
        : root{ make_shared<node>() }
    {
    }
    void insert(const string& s)
    {
        auto cur_node = root;
        cur_node->cnt++;
        for (auto it = s.begin(); it != s.end(); it++) {
            auto tmp_result = cur_node->next.insert({ *it, make_shared<node>() });
            cur_node = get<0>(tmp_result)->second;
            cur_node->cnt++;
        }
        cur_node->is_end = true;
    }
    bool contains(const string& s) const
    {
        auto cur_node = root;
        for (auto it = s.begin(); it != s.end(); it++) {
            auto next_node_it = cur_node->next.find(*it);
            if (next_node_it == cur_node->next.end()) {
                return false;
            } else {
                cur_node = next_node_it->second;
            }
        }
        return cur_node->is_end ? true : false;
    }
    string get_unique_prefix(const string& s) const
    {
        ostringstream out;
        auto cur_node = root;

        for (auto it = s.begin(); it != s.end(); it++) {
            auto next_node_it = cur_node->next.find(*it);
            if (next_node_it == cur_node->next.end()) {
                throw make_shared<exception>();
            } else {
                out << *it;
                cur_node = next_node_it->second;
                if (cur_node->cnt == 1)
                    break;
            }
        }
        return out.str();
    }
};

int main(int argc, char** argv)
{
    vector<string> vs{ "hehe", "he", "hehgaaa" };
    trie t;

    for (const auto& s : vs) {
        t.insert(s);
    }
    for (const auto& s : vs) {
        cout << s << ":" << t.get_unique_prefix(s) << endl;
    }
}