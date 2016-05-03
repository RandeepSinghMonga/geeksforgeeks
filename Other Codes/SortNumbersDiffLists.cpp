#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector<int> sortNos(vector<vector<int>>&vec){
    vector<int> ans;
    priority_queue<int> pq;
    for(int i=0;i<vec.size();i++){
        for(int j=0;j<vec[i].size();j++){
            pq.push(vec[i][j]);
        }
    }
    while(pq.size()>0){
        ans.push_back(pq.top());
        pq.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    int arr1[] = {30,40,50};
    int arr2[] = {35,45};
    int arr3[] = {10,60,70,80,100};
    vector<int> vec1(arr1,arr1 + sizeof(arr1)/sizeof(arr1[0]));
    vector<int> vec2(arr2,arr2 + sizeof(arr2)/sizeof(arr2[0]));
    vector<int> vec3(arr3,arr3 + sizeof(arr3)/sizeof(arr3[0]));
    vector<vector<int>> vec;
    vec.push_back(vec1);vec.push_back(vec2);vec.push_back(vec3);
    vector<int> ans = sortNos(vec);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}
