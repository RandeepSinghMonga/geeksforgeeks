#include <iostream>
#include <vector>
using namespace std;

int isSubsetSumR(int set[],int n,int sum,vector <int> ans){
    if(sum==0){
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        return 1;
    }
    if(sum<0 || n==0){
        return 0;
    }
    else{
        if(isSubsetSumR(set,n-1,sum,ans))return 1;
        ans.push_back(set[n-1]);
        return isSubsetSumR(set,n-1,sum-set[n-1],ans);
    }
}

int isSubsetSumDP(int set[],int n,int sum){
    int dp[sum+1][n];
    for(int i=0;i<=sum;i++){
        for(int j=0;j<n;j++){
            if(i==0){
                dp[i][j]=1;
            }
            else if(j==0){
                dp[i][j]=0;
            }
            else{
                dp[i][j]=dp[i][j-1];
                if(!dp[i][j] && i-set[j]>=0){
                    dp[i][j]=dp[i-set[j]][j-1];
                }
            }
        }
    }
    return dp[sum][n-1];
}

int main(){
    int set[] = {3, 1, 5, 9, 12};
    int sum = 15;
    int n = sizeof(set)/sizeof(set[0]);
    vector<int> ans;
    if (isSubsetSumR(set, n, sum, ans) == true)
      cout<<"Found a subset with given sum"<<endl;
    else
        cout<<"No subset with given sum"<<endl;
    if (isSubsetSumDP(set, n, sum) == true)
      cout<<"Found a subset with given sum"<<endl;
    else
        cout<<"No subset with given sum"<<endl;
    return 0;
}
