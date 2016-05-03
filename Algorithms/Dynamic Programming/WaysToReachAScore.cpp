#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int count(int n){
    int arr[n+1];
    memset(arr,0,sizeof(arr));
    arr[0]=1;
    for(int i=3;i<=n;i++){
        arr[i]+=arr[i-3];
    }
    for(int i=5;i<=n;i++){
        arr[i]+=arr[i-5];
    }
    for(int i=10;i<=n;i++){
        arr[i]+=arr[i-10];
    }
    return arr[n];
}

int main(){
    int n = 20;
    cout<<count(n)<<endl;
    n = 13;
    cout<<count(n)<<endl;
    return 0;
}
