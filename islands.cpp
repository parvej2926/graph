#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> grid;
vector<vector<bool>> vis;

int n, m;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int x, int y) {
    vis[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < n &&
            ny >= 0 && ny < m &&
            !vis[nx][ny] &&
            grid[nx][ny] == '1') {

            dfs(nx, ny);
        }
    }
}

int main() {
    cin >> n >> m;

    grid.resize(n, vector<char>(m));
    vis.resize(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int islands = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '1' && !vis[i][j]) {
                dfs(i, j);
                islands++;
            }
        }
    }

    cout << islands << '\n';

    return 0;
}