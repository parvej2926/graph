#include <iostream>
#include <vector>
using namespace std;
int n, m;
int ans = 0;
void dfs(int node, int parent, int cats, vector<int>& a, vector<vector<int>>& adj) {
    if (a[node] == 1) cats++;
    else cats = 0;
    if (cats > m) return;
    bool leaf = true;
    for (int next : adj[node]) {
        if (next == parent) continue;
        leaf = false;
        dfs(next, node, cats, a, adj);
    }
    if (leaf)
        ans++;
}
int main() {
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0, 0, a, adj);
    cout << ans;
    return 0;
}