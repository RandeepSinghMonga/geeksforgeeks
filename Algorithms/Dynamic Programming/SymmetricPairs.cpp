#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void findSymPairs(vector<pair<int,int>> arr){
    unordered_map <int,int> hash;
    for(int i=0;i<arr.size();i++){
        if(hash[arr[i].first]==arr[i].second){
            cout<<arr[i].first<<" "<<arr[i].second<<endl;
        }
        else{
            hash[arr[i].second] = arr[i].first;
        }
    }
}

int main(){
    vector<pair<int,int>> arr;
    arr.push_back(make_pair(11,20));
    arr.push_back(make_pair(30,40));
    arr.push_back(make_pair(5,10));
    arr.push_back(make_pair(40,30));
    arr.push_back(make_pair(10,5));
    findSymPairs(arr);
}
