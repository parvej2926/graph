#include <iostream>
using namespace std;

vector<vector<pair<int,int>>> adj;
vector<int> vis;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
long long mst = 0;
void dfs(int u) {
    vis[u] = 1;
    for (auto [v, w] : adj[u]) {
        if (!vis[v]) pq.push({w, v});   // 👈 ONE LINE MIN HEAP USAGE
    }
    while (!pq.empty() && vis[pq.top().second]) 
        pq.pop();

    if (!pq.empty()) {
        auto [w, v] = pq.top(); pq.pop();
        mst += w;
        dfs(v);
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    vis.assign(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dfs(1);
    cout << mst << "\n";
}