#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m, src;
    // INPUT:
    // 5 6 1
    // n = 5 nodes, m = 6 edges, src = 1
    cin >> n >> m >> src;
    vector<vector<pair<int,int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        // Example edges:
        // 1 2 2
        // 1 3 4
        // 2 3 1
        // 2 4 7
        // 3 5 3
        // 4 5 1
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    // adj[1]= {(2,2),(3,4)}
    // adj[2]={(1,2),}
    vector<int> dist(n + 1, 1e9);
    // dist initially:
    // 1 -> inf
    // 2 -> inf
    // 3 -> inf
    // 4 -> inf
    // 5 -> inf
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[src] = 0;   // dist[1] = 0
    pq.push({0, src}); // pq = (0,1)
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        int d = top.first;   // current distance
        int node = top.second;
        // Step 1: (0,1)
        // node = 1, d = 0
        if (d > dist[node]) continue;
        // ----- NODE 1 PROCESS -----
        for (auto it : adj[node]) {
            int v = it.first;   // neighbour
            int w = it.second;  // weight
            // From node 1:
            // (1 -> 2, w=2)
            // (1 -> 3, w=4)
            if (dist[node] + w < dist[v]) {
                // 1 -> 2:
                // 0 + 2 < inf => true
                dist[v] = dist[node] + w;
                // dist[2] = 2
                // dist[3] = 4
                pq.push({dist[v], v});
                // pq now:
                // (2,2), (4,3)
            }
        }
    }
    // ----- NEXT STEP PROCESSING -----
    // pop (2,2)
    // node = 2
    // from 2:
    // 2 -> 3 (1)
    // 2 -> 4 (7)

    // update:
    // dist[3] = 3 (better than 4)
    // dist[4] = 9

    // pop (3,3)
    // from 3:
    // 3 -> 5 (3)
    // dist[5] = 6

    // pop (6,5)
    // from 5:
    // update 4 -> 7 (better than 9)

    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    // FINAL OUTPUT:
    // 0 2 3 7 6

    return 0;
}
