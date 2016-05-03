#include <iostream>
#include <climits>
using namespace std;

int MatrixChainOrderR(int arr[],int i,int j){
    if(i==j){
        return 0;
    }
    else{
        int min=INT_MAX;
        for(int k=i;k<j;k++){
            int ans = arr[i-1]*arr[k]*arr[j]+
            MatrixChainOrderR(arr,i,k)+
            MatrixChainOrderR(arr,k+1,j);
            if(ans<min){
                min=ans;
            }
        }
        return min;
    }
}

int MatrixChainOrderDP(int arr[],int n){
    int dp[n+1][n+1];
    for(int i=1;i<=n;i++){
        dp[i][i]=0;
    }
    for(int x=2;x<=n;x++){
        for(int i=1;i<=n-x+1;i++){
            int j = x+i-1;
            dp[i][j]=INT_MAX;
            for(int k=i;k<j;k++){
                int ans = arr[i-1]*arr[k]*arr[j]+
                dp[i][k]+
                dp[k+1][j];
                if(ans<dp[i][j]){
                    dp[i][j]=ans;
                }
            }
        }
    }
    return dp[1][n-1];
}

int main(){
    int arr[] = {1, 2, 3, 4};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<MatrixChainOrderR(arr,1,size-1)<<endl;
    cout<<MatrixChainOrderDP(arr,size)<<endl;
    return 0;
}
