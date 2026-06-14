#include <iostream>
using namespace std;

struct Edge {
    int u, v, w;
};
int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);

    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    int source;
    cin >> source;

    vector<long long> dist(n, LLONG_MAX);
    dist[source] = 0;

    // Step 1: Relax all edges (n - 1 times)
    for (int i = 0; i < n - 1; i++) {
        for (auto &e : edges) {
            if (dist[e.u] != LLONG_MAX && dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
            }
        }
    }

    // Step 2: Check negative cycle
    bool negativeCycle = false;

    for (auto &e : edges) {
        if (dist[e.u] != LLONG_MAX && dist[e.u] + e.w < dist[e.v]) {
            negativeCycle = true;
            break;
        }
    }

    // Output
    if (negativeCycle) {
        cout << "Negative cycle detected\n";
    } else {
        for (int i = 0; i < n; i++) {
            cout << "Distance to " << i << " = " << dist[i] << "\n";
        }
    }

    return 0;
}