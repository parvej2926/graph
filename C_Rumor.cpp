#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<int> visited;
vector<long long> cost;

long long mn;

void dfs(int node) {
    visited[node] = true;
    mn = min(mn, cost[node]);
    for (int nxt : adj[node]) {
        if (!visited[nxt]) {
            dfs(nxt);
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    cost.resize(n + 1);
    for (int i = 1; i <= n; i++)  cin >> cost[i];
    adj.resize(n + 1);
    visited.assign(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            mn = 1e9;
            dfs(i);
            ans += mn;
        }
    }
    cout << ans << endl;
}