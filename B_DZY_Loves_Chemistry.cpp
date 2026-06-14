#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1, vector<int>(n+1, 0));
    vector<bool> visited(n+1,0);
    for (int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        adj[x][y] = 1;
        adj[y][x] = 1;
    }
    int danger = 0;
    for(int i=1; i<=n; i++){

        int new_danger=1;
        stack<int>st;
        st.push(i);

        while (!st.empty()){
            int node = st.top();
            st.pop();

            if (!visited[node]){
                visited[node] = 1;

                for (int i=1; i<=n; i++){
                    if (adj[node][i] == 1 && !visited[i]){
                        new_danger*=2;
                        st.push(i);
                    }
                }
            }
        }
        if(danger<new_danger) danger= new_danger;
        visited.resize(n+1,0);
    }
    cout<<danger;
    return 0;
}