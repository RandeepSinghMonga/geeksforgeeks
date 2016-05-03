#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int maxSubArraySum(int arr[],int n){
    int dp[n];
    int max=0;
    dp[0]=arr[0]>0?arr[0]:0;
    for(int i=1;i<n;i++){
        dp[i]=dp[i-1]+arr[i];
        if(dp[i]<0){
            dp[i]=0;
        }
        if(max<dp[i]){
            max=dp[i];
        }
    }
    return max;
}

int main()
{
   int a[] =  {-2, -3, 4, -1, -2, 1, 5, -3};
   int n = sizeof(a)/sizeof(a[0]);
   int max_sum = maxSubArraySum(a, n);
   cout<<"Maximum contiguous sum is "<<max_sum<<endl;
   return 0;
}
