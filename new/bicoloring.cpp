#include <iostream>              // for input output
#include <vector>                // for adjacency list
#include <queue>                 // for BFS
using namespace std;

int main() {
    int n;                       // number of nodes
    while (cin >> n && n) {      // stop when n = 0
        int l;
        cin >> l;                // number of edges
        vector<vector<int>> graph(n);   // adjacency list
        // sample:
        // 0 -- 1
        // |
        // 2
        for (int i = 0; i < l; i++) {
            int u, v;
            cin >> u >> v;       // edge input
            graph[u].push_back(v); // store v in u list
            graph[v].push_back(u); // store u in v list
        }
        vector<int> color(n, -1);
        // -1 = not colored
        // 0 = first color
        // 1 = second color
        queue<int> q;            // BFS queue
        color[0] = 0;            // start node color
        q.push(0);               // push first node
        bool bipartite = true;
        while (!q.empty() && bipartite) {
            int node = q.front(); // take front node
            q.pop();              // remove it
            // visit all adjacent nodes
            for (int next : graph[node]) {
                // if not colored yet
                if (color[next] == -1) {
                    color[next] = 1 - color[node];
                    // if parent is 0 -> child becomes 1
                    // if parent is 1 -> child becomes 0
                    q.push(next);
                }
                // if adjacent nodes have same color
                else if (color[next] == color[node]) {

                    bipartite = false;
                    break;
                }
            }
        }
        if (bipartite) cout << "BICOLORABLE.\n";
        else cout << "NOT BICOLORABLE.\n";
    }
    return 0;
}