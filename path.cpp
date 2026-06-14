#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<vector<int>> edges(m, vector<int>(2));
    for(int i=0; i<m; i++){
        for(int j=0; j<2; j++){
            cin>>edges[i][j];
        }
    }
    vector<vector<int>>adj(n);
    for(int i=0; i<edges.size(); i++){
        int u= edges[i][0];
        int v= edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool reached=false;
    vector<int>stack;
    vector<bool>visited(m,false);
    int source, destination;
    cin>>source>>destination;
    stack.push_back(source);
    visited[source]=true;
    while (!stack.empty()){
        int p= stack.back();
        stack.pop_back();
        visited[p]= true;
        if(p==destination){
            reached= true;
            break;
        }
        for(int i=0; i<adj[p].size(); i++){
            int neighbour= adj[p][i];
            if(!visited[neighbour]){
                stack.push_back(neighbour);
                visited[neighbour]=true;
            }
        }
    }
    if(reached==true) cout<<"reached";
    else cout <<"not reached";
    return reached;
}
