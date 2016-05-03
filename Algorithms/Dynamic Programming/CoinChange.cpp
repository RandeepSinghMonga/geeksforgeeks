#include <iostream>
using namespace std;

int coinChangeR(int arr[],int n,int sum){
    if(sum==0){
        return 1;
    }
    else if (sum<0){
        return 0;
    }
    else if (n==0){
        return 0;
    }
    else{
        return coinChangeR(arr,n-1,sum) + coinChangeR(arr,n,sum-arr[n-1]);
    }
}

int coinChangeDP(int arr[],int n,int sum){
    int dp[sum+1][n];
    for(int i =0;i<n;i++){
        dp[0][i]=1;
    }
    //i - sum
    //j - denomination
    for(int i=1;i<=sum;i++){
        for(int j=0;j<n;j++){
            dp[i][j]=0;
            if(j>=1){
                dp[i][j] += dp[i][j-1];
            }
            if(i>=arr[j]){
                dp[i][j] += dp[i-arr[j]][j];
            }
        }
    }
    //printing the dp matrix
    for(int i=0;i<=sum;i++){
        for(int j=0;j<n;j++){
            cout<<dp[i][j];
        }
        cout<<endl;
    }
    return dp[sum][n-1];
}

int main(){
    int arr[] = {1, 2, 3};
    int m = sizeof(arr)/sizeof(arr[0]);
    cout<<coinChangeR(arr,m,4)<<endl;
    cout<<coinChangeDP(arr,m,4)<<endl;
    return 0;
}
