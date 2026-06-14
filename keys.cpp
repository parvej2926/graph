#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> rooms;
vector<bool> visited;

void dfs(int room) {
    visited[room] = true;

    for (int key : rooms[room]) {
        if (!visited[key]) {
            dfs(key);
        }
    }
}

int main() {
    int n;
    cin >> n;

    rooms.resize(n);
    visited.resize(n, false);

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;

        while (k--) {
            int key;
            cin >> key;
            rooms[i].push_back(key);
        }
    }

    dfs(0);

    bool ok = true;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            ok = false;
            break;
        }
    }

    cout << (ok ? "true" : "false") << '\n';

    return 0;
}