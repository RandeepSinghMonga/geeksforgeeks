#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int checkDuplicatesWithinK(int arr[],int n,int k){
    map <int,int> hash;
    for(int i=0;i<n;i++){
        if(hash[arr[i]] && hash[arr[i]]<=k){
            return 1;
        }
        hash[arr[i]]=i+1;
    }
    return 0;
}

int main(){
    int arr[] = {10, 5, 3, 4, 3, 5, 6};
    if (checkDuplicatesWithinK(arr,sizeof(arr)/sizeof(arr[0]),3))
        cout<<"Duplicates within k distance ";
    else
        cout<<"No Duplicates";
}
