#include<iostream>
#include<queue>
using namespace std;

int main(){
    int m,n;
    cin>>n>>m;
    vector<vector<int>>adj(n,vector<int>(n,0));

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    vector<int>vis(n,0);
    queue<int>q;
    vector<int>bfs;

    int start = 0;
    vis[start] = 1;
    q.push(start);

    while(!q.empty()){ 
        int node = q.front();
        bfs.push_back(node);
        q.pop();

        for(int i=0;i<n;i++){ 
        if(adj[node][i]== 1 && vis[i]==0){
            q.push(i);
            vis[i]=1;
        }
    }
}
    cout<<"BFS:\n";
   for(auto it:bfs){
    cout<<it <<" "<<endl;
   }
   return 0;
}

