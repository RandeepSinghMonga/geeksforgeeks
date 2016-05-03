#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int minJumpsR(int arr[],int i,int n){
    if(i>=n){
        return 0;
    }
    else{
        int min = INT_MAX,temp;
        for(int k=i+1;k<=arr[i]+i && k<=n;k++){
            temp = minJumpsR(arr,k,n)+1;
            if(temp<min){
                min=temp;
            }
        }
        return min;
    }
}

int minJumpsDP(int arr[],int n){
    int dp[n];
    dp[0]=0;
    for(int i=1;i<n;i++){
        dp[i]=INT_MAX;
        for(int j=i-1;j>=0;j--){
            if( i<=j+arr[j] && dp[i]>dp[j]+1 ){
                dp[i]=dp[j]+1;
            }
        }
    }
    return dp[n-1];
}

int main(){
    int arr[] = {1, 3, 6, 3, 2, 3, 6, 8, 9, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Minimum number of jumps to reach end is "<<minJumpsR(arr, 0, n-1)<<endl;
    cout<<"Minimum number of jumps to reach end is "<<minJumpsDP(arr,n)<<endl;
    return 0;
}
