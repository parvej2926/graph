#include <iostream>
using namespace std;

int main() {
    vector<vector<int>> image = {
        {1,1,1},
        {1,1,0},
        {1,0,1}
    };
    int sr = 1, sc = 1, color = 2;
    int original = image[sr][sc];
    if (original == color) {
        cout<<"no change";
    }
    int m = image.size();
    int n = image[0].size();
    vector<pair<int,int>> st;
    st.push_back({sr, sc});

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (!st.empty()) {
        auto cur = st.back();
        st.pop_back();

        int r = cur.first;
        int c = cur.second;

        image[r][c] = color;

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                image[nr][nc] == original) {
                st.push_back({nr, nc});
            }
        }
    }

    for (auto &row : image) {
        for (auto x : row) cout << x << " ";
        cout << endl;
    }

    return 0;
}
