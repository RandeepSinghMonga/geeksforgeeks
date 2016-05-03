#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int pairAndSum(int arr[],int n){
    int ans=0;
    for(int i=0;i<32;i++){
        int x = 1<<i;
        int sum=0;
        for(int j=0;j<n;j++){
            if(arr[j]&x){
                sum++;
            }
        }
        ans+= x*(sum*(sum-1)/2);
    }
    return ans;
}

int main(){
    int arr[] = {5, 10, 15};
    int n = sizeof(arr) / sizeof (arr[0]);
    cout << pairAndSum(arr, n) << endl;
    return 0;
}
