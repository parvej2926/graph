#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<int>> adj;
vector<bool> vis;

void dfs(int node) {
    vis[node] = true;

    for (int nxt : adj[node]) {
        if (!vis[nxt]) {
            dfs(nxt);
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        char last;
        cin >> last;

        adj.assign(26, vector<int>());
        vis.assign(26, false);

        string s;
        cin.ignore();

        while (getline(cin, s)) {
            if (s.empty()) break;

            int u = s[0] - 'A';
            int v = s[1] - 'A';

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int limit = last - 'A';
        int components = 0;

        for (int i = 0; i <= limit; i++) {
            if (!vis[i]) {
                dfs(i);
                components++;
            }
        }

        cout << components << "\n";

        if (t) cout << "\n";
    }

    return 0;
}