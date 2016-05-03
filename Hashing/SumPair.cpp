#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int hasArrayTwoCandidates(int arr[],int n,int sum){
    map<int,bool> hash;
    for(int i=0;i<n;i++){
        if(hash[arr[i]] == 1){
            cout<<arr[i]<<" "<<sum-arr[i]<<endl;
            return 1;
        }
        hash[sum-arr[i]] = 1;
    }
    return 0;
}

int main(){
    int arr[] = {1, 4, 45, 6, 10, -8};
    int sum = 16;
    int n = sizeof(arr)/sizeof(arr[0]);
    if( hasArrayTwoCandidates(arr,n,sum))
        cout<<"Array has two elements with sum 16";
    else
        cout<<"Array doesn't have two elements with sum 16 ";
    return 0;
}
