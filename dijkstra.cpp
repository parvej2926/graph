//shortest path
//src node = 0 
//min-heap{dist,node}
//shorter dist at the top
//distance arr


#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
    int n, edge, src;// 5 6 1
    cin >> n >> edge >> src;
    // adjacency list
    vector<vector<pair<int,int>>> adj(n+1);
    for (int i = 0; i < edge; i++) {
        int u, v, w;
        cin >> u >> v >> w;
       
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        
    }
    vector<int> dist(n+1 , 1e9); //dist if every node is ind initially

    priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>> > pq;
    dist[src] = 0;              //dist of src assign 0
    pq.push({0, src});          //weight and node
    // pq:(0,1)
    while (!pq.empty()){
        
        auto top = pq.top();
        pq.pop();
        int d = top.first;       
        int node = top.second;
       
        // if (d > dist[node]) {       // 0 > inf false (for safety not necessary)
        //     continue;
        // }
        // visit all neighbours
        for (auto it : adj[node]) {   // adj[1]={{2 ,2} {3,4}}
            int v = it.first; // 2 destination 3
            int w = it.second;// 2 weight 4
            if (dist[node] + w < dist[v]) {     // 0 + 2 < inf
                dist[v] = dist[node] + w;                 // dist[2] = 2
                pq.push({dist[v], v}); // (2,2)
            }
        }
    }
    cout << "Shortest Distance:\n";
    for (int i = 1; i <= n; i++) {
        cout << "Node " << i<< " = "<< dist[i]<< endl;
    }
    return 0;
}
