#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int u, v, w;
};

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        int n, m;
        cin >> n >> m;

        vector<Edge> edges;

        for (int i = 0; i < m; i++) {
            int x, y, t;
            cin >> x >> y >> t;
            edges.push_back({x, y, t});
        }

        vector<int> dist(n, 0);  // important trick: all 0 (super source)

        bool negativeCycle = false;

        // relax edges n-1 times
        for (int i = 0; i < n - 1; i++) {
            for (auto &e : edges) {
                if (dist[e.v] > dist[e.u] + e.w) {
                    dist[e.v] = dist[e.u] + e.w;
                }
            }
        }

        // check nth iteration for negative cycle
        for (auto &e : edges) {
            if (dist[e.v] > dist[e.u] + e.w) {
                negativeCycle = true;
                break;
            }
        }

        cout << (negativeCycle ? "possible" : "not possible") << "\n";
    }

    return 0;
}