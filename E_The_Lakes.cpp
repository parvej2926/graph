#include <iostream>
#include <vector>
using namespace std;

long long dfs(int r, int c,vector<vector<int>>& a,vector<vector<int>>& visited) {
    int n = a.size();
    int m = a[0].size();
    visited[r][c] = 1;
    long long sum = a[r][c];
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc] && a[nr][nc] > 0) {
            sum += dfs(nr, nc, a, visited);
        }
    }
    return sum;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<long long> lakes;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && a[i][j] > 0) {
                    lakes.push_back(dfs(i, j, a, visited));
                }
            }
        }
        long long ans=0;
        for (auto x : lakes)
             ans = max(ans, x);

            cout << ans << "\n";    
        }

    return 0;
}