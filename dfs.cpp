#include <iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>v(n,vector<int>(n,0));
    for(int i=0; i<m; i++){
        int x,y;
        cin>>x>>y;
        v[x][y]=1;
        v[y][x]=1;
    }
    int src, dest;
    cin>>src>>dest;
    vector<int>st,visited(n,0),res;
    res.push_back(src);
    st.push_back(src);
    visited[src]=0;
    while(!st.empty()){
        int node=st.back();
        st.pop_back();
        if(node==dest){
            for(auto it: res) cout<<it<<"   "<<endl;
            cout<<"Reached the destination";
            return 0;
        }
        for(int i=0; i<v[i].size(); i++){
            if(v[node][i]==1 && !visited[i]){
                st.push_back(i);
                visited[i]=1;
                res.push_back(i+1);
            }
        }
    }
    cout<<"Not reached";
    return 0;
}
