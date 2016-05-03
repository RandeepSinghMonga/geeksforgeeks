#include <iostream>
using namespace std;
#include <climits>
#define R 3
#define C 3

int min(int a,int b){
    return a<b?a:b;
}

int min(int a,int b,int c){
    return min(min(a,b),c);
}

int minCostPathR(int arr[R][C],int m,int n){
    if(n<0 || m<0){
        return INT_MAX;
    }
    else if(m==0 && n==0){
        return arr[m][n];
    }
    else{
        return arr[m][n] + min(minCostPathR(arr,m-1,n-1),minCostPathR(arr,m,n-1),minCostPathR(arr,m-1,n));
    }
}
int minCostPathDP(int arr[R][C],int n,int m){
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 && j==0){
                dp[i][j]=arr[i][j];
            }
            else if(i==0){
                dp[i][j]=dp[i][j-1]+arr[i][j];
            }
            else if(j==0){
                dp[i][j]=dp[i-1][j]+arr[i][j];
            }
            else{
                dp[i][j]= arr[i][j]+min(dp[i-1][j-1],dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    return dp[n][m];
}
int main()
{
   int cost[R][C] = { {1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3} };
   cout<<minCostPathR(cost, 2, 2)<<endl;
   cout<<minCostPathDP(cost, 2, 2)<<endl;
   return 0;
}
