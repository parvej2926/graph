#include<iostream>
using namespace std;

void merge(vector<int>&arr,int beg,int mid,int end){
    int n1 = mid-beg+1;
    int n2 = end - mid;
    vector<int>l(n1),r(n2);

    for(int i=0;i<n1;i++){
        l[i] = arr[beg+i];
    }
    for(int i=0;i<n2;i++){
        r[i] = arr[mid+1+i];
    }

    int i=0,j=0,k=beg;
    while(i<n1 && j<n2){
        if(l[i]<r[j]){
            arr[k++]=l[i++];
        }
        else{
            arr[k++]=r[j++];
        }
    }

    while(i<n1){
        arr[k++]=l[i++];
    }
    while(j<n2){
        arr[k++]=r[j++];
    }


}

void mergesort(vector<int> &arr,int beg,int end){
    int mid = (beg+end)/2;
    if(beg>=end) return;
    mergesort(arr,beg,mid);
    mergesort(arr,mid+1,end);
    merge(arr,beg,mid,end);
}

int main() {
    int n=4;     //n=8

    vector<int> arr = {4,3,2,1};

    mergesort(arr, 0, 3);

    cout << "Sorted array:\n";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}

