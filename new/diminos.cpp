#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> graph;
vector<bool> visited;
// DFS to simulate falling dominos
void dfs(int node) {
    visited[node] = true;        // mark current domino as fallen
    for (int nxt : graph[node]) {
        if (!visited[nxt]) {
            dfs(nxt);            // trigger next domino
        }
    }
}
int main() {
    int T;
    cin >> T;                    // number of test cases
    while (T--) {
        int n, m, l;
        cin >> n >> m >> l;      // dominos, relations, manual knocks
        graph.assign(n + 1, vector<int>());
        visited.assign(n + 1, false);
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            graph[x].push_back(y);
        }
        for (int i = 0; i < l; i++) {
            int z;
            cin >> z;
            if (!visited[z]){
                dfs(z);
            }
        }
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (visited[i]) count++;
        }
        cout << count << "\n";
    }
    return 0;
}