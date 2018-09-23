/*******************************************
Problem: Trie tree.
Remark: What character a node represents depends on the key of the map in the node's parent. The node itself doesn't store the character.
Author: furrybear<fbcll@outlook.com>
********************************************/
#include <iostream>
#include <memory>
#include <numeric>
#include <unordered_map>

using namespace std;

class trie {
protected:
    struct node {
        bool is_end;
        unordered_map<char, shared_ptr<node>> next;
        node()
            : is_end{ false }
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
        for (auto it = s.begin(); it != s.end(); it++) {
            auto tmp_result = cur_node->next.insert({ *it, make_shared<node>() });
            cur_node = get<0>(tmp_result)->second;
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
};

int main(int argc, char** argv)
{
    trie t;
    string target;
    bool result;

    target = "hehe";
    cout << "Insert \"" << target << "\"" << endl;
    t.insert(target);

    target = "hehe";
    result = t.contains(target);
    cout << "Result of finding \"" << target << "\":" << result << endl;
    target = "heh";
    result = t.contains(target);
    cout << "Result of finding \"" << target << "\":" << result << endl;
    target = "hehg";
    result = t.contains(target);
    cout << "Result of finding \"" << target << "\":" << result << endl;

    target = "heh";
    cout << "Insert \"" << target << "\"" << endl;
    t.insert(target);

    target = "hehe";
    result = t.contains(target);
    cout << "Result of finding \"" << target << "\":" << result << endl;
    target = "heh";
    result = t.contains(target);
    cout << "Result of finding \"" << target << "\":" << result << endl;
    target = "hehg";
    result = t.contains(target);
    cout << "Result of finding \"" << target << "\":" << result << endl;

    target = "hehg";
    cout << "Insert \"" << target << "\"" << endl;
    t.insert(target);

    target = "hehe";
    result = t.contains(target);
    cout << "Result of finding \"" << target << "\":" << result << endl;
    target = "heh";
    result = t.contains(target);
    cout << "Result of finding \"" << target << "\":" << result << endl;
    target = "hehg";
    result = t.contains(target);
    cout << "Result of finding \"" << target << "\":" << result << endl;
}