#include <iostream>
using namespace std;

int maxSumISR(int arr[],int n,int *max){
    if(n==1){
        return arr[0];
    }
    else{
        int temp_max = 0;
        int imax;
        for(int i=0;i<n-1;i++){
            imax = maxSumISR(arr,i+1,max);
            if(imax > *max){
                *max = imax;
            }
            if(arr[i]<arr[n-1] && imax>temp_max){
                temp_max = imax;
            }
        }
        return temp_max + arr[n-1];
    }
}

int maxSumISDP(int arr[],int n){
    int dp[n];
    dp[0]=arr[0];
    for(int i=1;i<n;i++){
        dp[i]=0;
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i] && dp[j]>dp[i]){
                dp[i]=dp[j];
            }
        }
        dp[i]+=arr[i];
    }
    int max = dp[0];
    for(int i=1;i<n;i++){
        if(dp[i]>max){
            max = dp[i];
        }
    }
    return max;
}

int main(){
    int arr[] = {1, 101, 2, 3, 100, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int max = 0;
    maxSumISR(arr,n,&max);
    cout<<"Sum of maximum sum increasing subsequence is "<<max<<endl;
    cout<<"Sum of maximum sum increasing subsequence is "<<maxSumISDP(arr,n)<<endl;
    return 0;
}
