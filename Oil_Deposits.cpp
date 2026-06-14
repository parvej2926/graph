#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> grid;
vector<vector<bool>> vis;

int m, n;

// 8 directions
int dx[] = {-1,-1,-1, 0,0, 1,1,1};
int dy[] = {-1, 0, 1,-1,1,-1,0,1};

void dfs(int x, int y) {
    vis[x][y] = true;

    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < m &&
            ny >= 0 && ny < n &&
            !vis[nx][ny] &&
            grid[nx][ny] == '@') {
            dfs(nx, ny);
        }
    }
}

int main() {
    while (true) {
        cin >> m >> n;
        if (m == 0) break;

        grid.assign(m, vector<char>(n));
        vis.assign(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        int deposits = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '@' && !vis[i][j]) {
                    dfs(i, j);
                    deposits++;
                }
            }
        }

        cout << deposits << '\n';
    }

    return 0;
}