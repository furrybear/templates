/*******************************************
Problem: Union find (并查集)
Author: furrybear<fbcll@outlook.com>
********************************************/
#include <iostream>
#include <vector>

using namespace std;

namespace std {
class union_find {
    // Parent of each vertices in disjoint sets (不交集).
    // Disjoint sets are stared as a forest.
    // If the parent of a certain vertex is itself, which means the vertex is the root of the disjoint set it belongs to.
    vector<int> parents;
    // Height of tree rooted at each vertex. If the tree contains only one vertex, the height is 0.
    vector<int> tree_heights;
    // Find the root of the disjoint set containing v, and set v's parent as it.
    int find_root(int v)
    {
        if (parents[v] == v)
            return v;
        else
            return parents[v] = find_root(parents[v]);
    }

public:
    union_find(int vertex_num)
        : parents(vertex_num)
        , tree_heights(vertex_num, 0)
    {
        for (int i = 0; i < vertex_num; ++i)
            parents[i] = i;
    }
    bool belong_to_same_set(int v1, int v2)
    {
        return find_root(v1) == find_root(v2);
    }
    // Unite two disjoint sets
    void unite(int v1, int v2)
    {
        v1 = find_root(v1);
        v2 = find_root(v2);
        if (v1 == v2)
            return;

        if (tree_heights[v1] < tree_heights[v2]) {
            parents[v1] = v2;
        } else {
            parents[v2] = v1;
            if (tree_heights[v1] == tree_heights[v2]) {
                tree_heights[v1]++;
            }
        }
    }
};
}

int main(int argc, char** argv)
{
    union_find uf(100);
    cout << "If 4,5 belong to same set?: " << uf.belong_to_same_set(4, 5) << endl;
    cout << "Unite sets containing 4,5." << endl;
    uf.unite(4, 5);
    cout << "If 4,5 belong to same set?: " << uf.belong_to_same_set(4, 5) << endl;
}