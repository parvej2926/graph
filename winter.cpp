#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> adj(n);
        vector<int> deg(n, 0);

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
            deg[u]++;
            deg[v]++;
        }

        // Center: all neighbors have degree > 1 (no leaf neighbors)
        int center = -1;
        for (int i = 0; i < n; i++) {
            bool allNonLeaf = true;
            for (int nb : adj[i]) {
                if (deg[nb] == 1) { allNonLeaf = false; break; }
            }
            if (allNonLeaf && deg[i] > 1) {
                center = i;
                break;
            }
        }

        int x = deg[center];

        // y = degree of any middle node - 1 (middle nodes are neighbors of center)
        int y = deg[adj[center][0]] - 1;

        cout << x << " " << y << "\n";
    }

    return 0;
}