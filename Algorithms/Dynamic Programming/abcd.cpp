#include <iostream>
using namespace std;
#include <bits/stdc++.h>

void findPairs(vector<int> A){
    int n = A.size();
    unordered_map <int,pair<int,int>> hash;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(hash.find(A[i]+A[j])==hash.end()){
                hash[A[i]+A[j]] = make_pair(A[i],A[j]);
            }
            else{
                cout<<A[i]<<" "<<A[j]<<" "<<hash[A[i]+A[j]].first<<" "<<hash[A[i]+A[j]].second<<endl;
            }
        }
    }
}

int main(){
    int arr[] = {3, 4, 7, 1, 2, 9, 8};
    int n  =  sizeof arr / sizeof arr[0];
    vector<int> A(arr,arr+n);
    findPairs(A);
    return 0;
}
