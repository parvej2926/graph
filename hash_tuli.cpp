#include<iostream>
using namespace std;

int main(){
    int ts,k,keys;
    cin>>ts>>k;
        vector<int>v(ts);

    for(int i=0;i<ts;i++){
        v[i]=-1;
    }
    for(int i=0;i<k;i++){
        cin>>keys;
        int index;
        index = (10+keys)%ts;
        while(v[index]!=-1){
            int h2=index = (keys+100)%ts;
            while(v[index]!=-1){
                index = (h2 +1)%ts;
            }
        }
        v[index] = keys;
    }
    for(int i=0;i<ts;i++){
        cout<<i<<" "<<v[i]<<endl;
    }
}
