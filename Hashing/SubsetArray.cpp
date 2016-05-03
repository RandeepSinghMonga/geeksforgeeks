#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int isSubset(int arr1[],int arr2[],int m,int n){
    map<int,bool> hash;
    for(int i=0;i<m;i++){
        hash[arr1[i]] = true;
    }
    int flag=1;
    for(int j=0;j<n;j++){
        cout<<hash[arr2[j]]<<endl;
        if(hash[arr2[j]]!=true){
            flag=0;
            break;
        }
    }
    return flag;
}

int main(){
    int arr1[] = {11, 2, 13, 21, 3, 7};
    int arr2[] = {11, 3, 7, 1};

    int m = sizeof(arr1)/sizeof(arr1[0]);
    int n = sizeof(arr2)/sizeof(arr2[0]);

    if(isSubset(arr1, arr2, m, n))
        cout<<"arr2[] is subset of arr1[] "<<endl;
    else
        cout<<"arr2[] is not a subset of arr1[] "<<endl;

    getchar();
    return 0;
}
