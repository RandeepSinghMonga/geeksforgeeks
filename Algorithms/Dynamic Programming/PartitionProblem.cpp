#include <bits/stdc++.h>
#include <iostream>
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
int findPartitionR(int arr[],int n){
    int sum = 0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    vector <int> nums;
    if(sum%2){
        return 0;
    }
    else if(isSubsetSumR(arr,n,sum/2,nums)){
        return 1;
    }
    return 0;
}

int main(){
    int arr[] = {3, 1, 5, 9, 12};
    int n = sizeof(arr)/sizeof(arr[0]);
    if (findPartitionR(arr,n))
        cout<<"Can be divided into two subsets of equal sum"<<endl;
    else
        cout<<"Can not be divided into two subsets of equal sum"<<endl;
    return 0;
}
