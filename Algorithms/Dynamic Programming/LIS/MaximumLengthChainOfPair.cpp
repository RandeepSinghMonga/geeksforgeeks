#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool compare(pair<int,int>a, pair<int,int>b){
    return (a.first > b.first ? 0 : 1);
}

int maxChainLengthDP(pair<int,int> arr[],int n){
    int dp[n];
    dp[0]=1;
    int max = dp[0];
    for(int i=1;i<n;i++){
        dp[i]=1;
        for(int j=i-1;j>=0;j--){
            if((arr[j].second <= arr[i].first) && dp[j]>=dp[i]){
                dp[i]=dp[j]+1;
            }
        }
        if(dp[i]>max){
            max = dp[i];
        }
    }
    return max;
}

int main(){
    pair <int,int> arr[] = { make_pair(5, 24), make_pair(27, 40), make_pair(15, 25), make_pair(50, 60) };
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+n,compare);
    cout<<"Length of maximum size chain is "<<maxChainLengthDP( arr, n )<<endl;
    return 0;
}
