#include <iostream>
using namespace std;

int max(int a,int b){
    return a>b?a:b;
}

int knapSackR(int W,int wt[],int val[],int n){
    if(n==0 || W==0){
        return 0;
    }
    else if(wt[n-1]>W){
        return knapSackR(W,wt,val,n-1);
    }
    else{
        return max(val[n-1]+knapSackR(W-wt[n-1],wt,val,n-1),knapSackR(W,wt,val,n-1));
    }
}

int knapSackDP(int W,int wt[],int val[],int n){
    int dp[n+1][W+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
            else if(wt[i-1]>j){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
            }
        }
    }
    return dp[n][W];
}

int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int  W = 50;
    int n = sizeof(val)/sizeof(val[0]);
    cout<<knapSackR(W, wt, val, n)<<endl;
    cout<<knapSackDP(W, wt, val, n)<<endl;
    return 0;
}
