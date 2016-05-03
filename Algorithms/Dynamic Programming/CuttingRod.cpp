#include <iostream>
#include <climits>
using namespace std;

int max(int a,int b){
    return a>b?a:b;
}

int cutRodR(int arr[],int n){
    if(n==0){
        return 0;
    }
    else{
        int max_value = INT_MIN;
        for(int i=0;i<n;i++){
            max_value = max(max_value,arr[i]+cutRodR(arr,n-i-1));
        }
        return max_value;
    }
}

int cutRodDP(int arr[],int n){
    int dp[n];
    dp[0]=arr[0];
    for(int i=1;i<n;i++){
        dp[i]=arr[i];
        for(int j=0;j<i-1;j++){
            dp[i]=max(dp[i],dp[i-j-1]+dp[j]);
        }
    }
    return dp[n-1];
}

int main()
{
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Maximum Obtainable Value is "<<cutRodR(arr, size)<<endl;
    cout<<"Maximum Obtainable Value is "<<cutRodDP(arr, size)<<endl;
    return 0;
}
