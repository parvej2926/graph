#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n = 6;
    vector<vector<int>> v = {
        {0,1},
        {0,2},
        {1,2},
        {3,4}
    };
    vector<vector<int>> adj(n, vector<int>(n, 0));
    for (int i = 0; i < v.size(); i++) {
        int u = v[i][0];
        int x = v[i][1];
        adj[u][x] = 1;
        adj[x][u] = 1;
    }
    vector<int> vis(n, 0);
    int grp = 0;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            vector<int> st;
            st.push_back(i);
            vis[i] = 1;
            int nodes = 0;
            int edges = 0;
            while (!st.empty()) {
                int node = st.back();
                st.pop_back();
                nodes++;
                for (int j = 0; j < n; j++) {
                    if (adj[node][j] == 1) {
                        edges++;
                        if (!vis[j]) {
                            vis[j] = 1;
                            st.push_back(j);
                        }
                    }
                }
            }
            edges /= 2;
            if (edges == nodes * (nodes - 1) / 2) {
                grp++;
            }
        }
    }
    cout << grp;
    return 0;
}
