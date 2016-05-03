#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int BuildingBridges(int bridges[],int n){
    int dp[n];
    dp[0]=1;
    int max = dp[0];
    for(int i=1;i<n;i++){
        dp[i]=1;
        for(int j=i-1;j>=0;j--){
            if(bridges[i]>bridges[j] && dp[j]>=dp[i]){
                dp[i]=dp[j]+1;
            }
        }
        cout<<dp[i]<<endl;
        if(max<dp[i]){
            max = dp[i];
        }
    }
    return max;
}

int main(){
    int arr[] = {8,1,4,3,5,2,6,7};
    int bridges[8];
    for(int i=0;i<8;i++){
        bridges[arr[i]-1] = i;
    }
    cout<<BuildingBridges(bridges,8)<<endl;
    return 0;
}
