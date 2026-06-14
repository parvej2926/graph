#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> isConnected(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> isConnected[i][j];
        }
    }
    // 1 1 0
    // 1 1 0
    // 0 0 1

    vector<int> vis(n, 0);
    int provinces = 0;

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            // DFS using vector as stack (manual simulation)
            vector<int> st;
            st.push_back(i);
            vis[i] = 1;

            while (!st.empty()) {
                int node = st.back();
                st.pop_back();

                for (int j = 0; j < n; j++) {
                    if (isConnected[node][j] == 1 && !vis[j]) {
                        vis[j] = 1;
                        st.push_back(j);
                    }
                }
            }

            provinces++;
        }
    }

    cout << provinces << endl;

    return 0;
}
