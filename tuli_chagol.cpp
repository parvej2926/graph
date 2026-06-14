#include <iostream>
using namespace std;
int main(){
    int n=7;
    vector<int>v(n,-1),keys={27,43,692,72};
    for(int i=0; i<keys.size(); i++){
        int index=keys[i]%n;
        int j=1;
        while(v[index]!=-1){
            int h2=index+j*(1+keys[i]%5);
            index=h2%7;
            j++;
        }
        v[index]=keys[i];
    }
    int i=1;
    for(auto it: v) cout<< it<<"        "<<i++<<endl;
    return 0;
}
