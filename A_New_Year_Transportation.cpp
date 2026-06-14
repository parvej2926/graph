#include<iostream>
using namespace std;

int main(){
    int n,t;
    cin>>n>>t;
    vector<int>cell(n);

    for(int i=0;i<n-1;i++){
        cin>>cell[i];
    }
    bool res = false;
    for(int i=0;i<n-1;i++){
        // if(i==cell.size()) break;
        if(i + cell[i] < t){
            i += cell[i];
        } 
        else if(i==t){
            res = true;
            break;
        }
        else break;
    }
    if(res) cout<<"YES";
    else cout<<"NO";
    
}