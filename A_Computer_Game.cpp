#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    while(n--){
        int p;
        cin>>p;
        vector<char>v1(p),v2(p);
        for(int i=0; i<p; i++) cin>>v1[i];
        for(int i=0; i<p; i++) cin>>v2[i];
        int cnt=0;
        for(int i=0; i<p; i++){
            if(v1[i]=='0' || v2[i]=='0') cnt++;
        }
        if(cnt==p) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}