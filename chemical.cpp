#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;  // 3 2
    vector<vector<int>> adj(n, vector<int>(n, 0));
    // 0   0   0
    // 0   0   0
    // 0   0   0
    vector<bool> visited(n, false); //      [false, false, false]
    for (int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;      // 1    2      // 2    3
        x--;
        y--;
        adj[x][y] = 1;
        adj[y][x] = 1;
    }
    // 0   1   0
    // 1   0   1
    // 0   1   0
    int components = 0;  // chemical 0
    for (int i = 0; i < n; i++){
        if (!visited[i]){       //
            components++;
            vector<int> stack;
            stack.push_back(i);     //  0
            while (!stack.empty()){
                int node = stack.back();    //  1
                stack.pop_back();       // 1
                if (!visited[node]){
                    visited[node] = true; //    [true, true, true]
                    for (int j = n - 1; j >= 0; j--){
                        if (adj[node][j] == 1 && !visited[j]){      // adj[1][2]= 1
                            stack.push_back(j); // 1
                        }
                    }
                }
            }
        }
    }
    long long ans = 1;
    for (int i = 0; i < n - components; i++)
        ans *= 2;
    cout << ans << endl;
    return 0;
}
