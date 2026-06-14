#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--; v--;

            adj[u].push_back(v);
            adj[v].push_back(u);

            degree[u]++;
            degree[v]++;
        }

        // find center (max degree)
        int center = 0;
        for (int i = 0; i < n; i++) {
            if (degree[i] > degree[center]) {
                center = i;
            }
        }

        int x = degree[center];

        // pick a middle node (neighbor of center)
        int middle = adj[center][0];

        int y = degree[middle] - 1;

        cout << x << " " << y << endl;
    }

    return 0;
}
