#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        v[x][y] = 1;
        v[y][x] = 1;
    }
    int src, dest;
    cin >> src >> dest;
    src--;
    dest--;
    vector<int> st;
    vector<int> visited(n, 0);
    vector<int> res;
    st.push_back(src);
    visited[src] = 1;
    res.push_back(src);
    while (!st.empty()) {
        int node = st.back();
        st.pop_back();
        // keep res aligned with current DFS path
        while (!res.empty() && res.back() != node) {
            res.pop_back();
        }
        if (node == dest) {
            cout << "Correct Path: ";
            for (auto it : res)
                cout << it + 1 << " ";
            cout << "\nReached destination";
            return 0;
        }
        for (int i = 0; i < n; i++) {
            if (v[node][i] == 1 && !visited[i]) {

                st.push_back(i);
                visited[i] = 1;

                res.push_back(i);
            }
        }
    }
    cout << "Not reached";
    return 0;
}