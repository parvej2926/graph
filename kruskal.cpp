//MSt 
//findparent
//if parents of two nodes(u->v) are different then group them and update parent of first node(u) as second(v)
//sort all edges according to weight
//disjoint set
//initially in parent arr every node is its own parent
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};
vector<int> parent;
int findParent(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = findParent(parent[x]);
}
int main() {
    int n, m;
    cin >> n >> m;    //nodes adges
    parent.resize(n);
    for (int i = 0; i < n; i++) parent[i] = i;   //each node is parent of itself initially
    vector<Edge> edges;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    //1 1 4
    //2 1 2
    //3 2 1
    sort(edges.begin(), edges.end(), [](Edge a, Edge b){    //sorting all the edges according to weight
        return a.w < b.w;
    });
    int cost = 0;
    for (auto e : edges) {
        int pu = findParent(e.u);
        int pv = findParent(e.v);
        if (pu != pv) {
            parent[pu] = pv;
            cost += e.w;
        }
    }
    cout << "MST Cost = " << cost << endl;
}