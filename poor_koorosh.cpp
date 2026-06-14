#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {

    while (true) {
        int n, m;
        cin >> n >> m;

        if (n == 0 && m == 0) break;

        int adj[1005][1005] = {0};
        vector<int> deg(n + 1, 0);

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;

            adj[u][v] = 1;
            adj[v][u] = 1;

            deg[u]++;
            deg[v]++;
        }

        // check isolated node
        bool bad = false;
        for (int i = 1; i <= n; i++) {
            if (deg[i] == 0) {
                bad = true;
                break;
            }
        }

        if (bad) {
            cout << "Poor Koorosh\n";
            continue;
        }

        // find odd degree nodes
        vector<int> odd;
        for (int i = 1; i <= n; i++) {
            if (deg[i] % 2 == 1)
                odd.push_back(i);
        }

        // case: already all even
        if (odd.size() == 0) {
            cout << 0 << "\n";
            continue;
        }

        int start = odd[0];
        int target = odd[1];

        // BFS
        vector<int> visit(n + 1, 0);
        vector<int> dist(n + 1, -1);
        queue<int> q;

        visit[start] = 1;
        dist[start] = 0;
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int i = 1; i <= n; i++) {
                if (adj[node][i] == 1 && !visit[i]) {

                    // degree constraint (important)
                    if (i != target && deg[i] < 3) continue;

                    visit[i] = 1;
                    dist[i] = dist[node] + 1;
                    q.push(i);
                }
            }
        }

        if (dist[target] == -1)
            cout << "Poor Koorosh\n";
        else
            cout << dist[target] << "\n";
    }

    return 0;
}