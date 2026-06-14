#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<vector<int>> times = {
        {2,1,1},
        {2,3,1},
        {3,4,1}
    };

    int n = 4;
    int k = 2;

    // adjacency matrix
    vector<vector<int>> adj(n, vector<int>(n, 0));
    for(int i = 0; i < times.size(); i++){
        int u = times[i][0] - 1;
        int v = times[i][1] - 1;
        int w = times[i][2];
        adj[u][v] = w;
    }

    // 0 means unvisited
    vector<int> dist(n, 0);

    dist[k - 1] = 1;

    vector<int> st;
    st.push_back(k - 1);

    while(!st.empty())
    {
        int u = st.back();
        st.pop_back();

        for(int v = 0; v < n; v++)
        {
            if(adj[u][v] != 0)
            {
                int w = adj[u][v];

                // first visit
                if(dist[v] == 0)
                {
                    dist[v] = dist[u] + w;
                    st.push_back(v);
                }

                // shorter path found
                else if(dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                    st.push_back(v);
                }
            }
        }
    }

    int ans = 0;

    for(int i = 0; i < n; i++)
    {
        if(dist[i] == 0)
        {
            cout << -1;
            return 0;
        }

        ans = max(ans, dist[i]);
    }

    cout << ans - 1;

    return 0;
}
