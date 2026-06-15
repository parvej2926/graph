#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main() {
    vector<vector<int>> times = {
        {2,1,1},
        {2,3,1},
        {3,4,1}
    };
    int n = 4;
    int k = 2;
    vector<vector<pair<int,int>>> adj(n);
    for(auto &e : times) {
        int u = e[0] - 1;
        int v = e[1] - 1;
        int w = e[2];
        adj[u].push_back({v, w});
    }
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    dist[k - 1] = 0;
    pq.push({0, k - 1});

    while(!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if(d > dist[u]) continue;

        for(auto [v, w] : adj[u]) {
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    int ans = 0;
    for(int d : dist) {
        if(d == INT_MAX) {
            cout << -1;
            return 0;
        }
        ans = max(ans, d);
    }
    cout << ans;
    return 0;
}