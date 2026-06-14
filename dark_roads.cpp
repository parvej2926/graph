#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Edge {
    int u, v, w;
};
bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}
vector<int> parent;
int find(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}
bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b)
        return false;
    parent[a] = b;
    return true;
}
int main() {
    int m, n;
    while (cin >> m >> n) {
        if (m == 0 && n == 0)
            break;
        vector<Edge> edges(n);
        long long total = 0;
        for (int i = 0; i < n; i++) {
            cin >> edges[i].u >> edges[i].v >> edges[i].w;
            total += edges[i].w;
        }
        sort(edges.begin(), edges.end(), cmp);
        parent.resize(m);
        for (int i = 0; i < m; i++)
            parent[i] = i;
        long long mst = 0;
        for (auto e : edges) {
            if (unite(e.u, e.v)) {
                mst += e.w;
            }
        }
        cout << total - mst << '\n';
    }
    return 0;
}