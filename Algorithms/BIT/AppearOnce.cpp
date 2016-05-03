#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int appearsOnceOutOfTwo(int arr[],int n){
    int ans = 0;
    for(int i=0;i<n;i++){
        ans^=arr[i];
    }
    return ans;
}

int appearsOnceOutOfThree(int arr[],int n){
    int result = 0;
    for(int j=0;j<32;j++){
        int x = 1<<j;
        int sum = 0;
        for(int i=0;i<n;i++){
            if(x & arr[i])
                sum++;
        }
        if(sum%3){
            result|=x;
        }
    }
    return result;
}

int main(){
    int arr[] = {1, 2, 2, 3, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<appearsOnceOutOfTwo(arr,n)<<endl;
    int vec[] = {12, 1, 12, 3, 12, 1, 1, 2, 3, 3};
    n = sizeof(vec)/sizeof(arr[0]);
    cout<<appearsOnceOutOfThree(vec,n);
    return 0;
}
