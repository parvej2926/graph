#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n, vector<int>(n, 0));

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    vector<int> vis(n, 0);
    stack<int> st;
    vector<int> dfs;

    int start = 0;
    st.push(start);

    while(!st.empty()){
        int node = st.top();
        st.pop();

        if(vis[node] == 0){
            vis[node] = 1;
            dfs.push_back(node);

            for(int i = 0; i < n; i++){
                if(adj[node][i] == 1 && vis[i] == 0){
                    st.push(i);
                }
            }
        }
    }

    cout << "DFS:\n";
    for(auto it : dfs){
        cout << it << " ";
    }
    cout << endl;

    return 0;
}