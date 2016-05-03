#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int nextSparse(int num){
    vector<int> temp;
    while(num != 0){
        temp.push_back(num&1);
        num >>= 1;
    }
    temp.push_back(0);
    int n = temp.size();
    int prev=0;
    for(int i = 1;i <n-1;i++)
       if(temp[i] == 1 && temp[i-1] == 1 && temp[i+1]!=1){
            temp[i+1]=1;
            for(int j=i;j>=prev;j--)
                temp[j]=0;
            prev=i+1;
        }
    int ans=0;
    for(int i =0;i<n;i++)
        ans+=temp[i]*(1<<i);
    return ans;
}

int main(){
    int x = 38;
    cout << "Next Sparse Number is " << nextSparse(x);
    return 0;
}
