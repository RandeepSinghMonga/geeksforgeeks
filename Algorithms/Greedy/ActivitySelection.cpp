#include <iostream>
#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;

bool compare(pair <int,int> i,pair <int,int> j){
    return i.second<j.second;
}

void printMaxActivities(int s[],int f[],int n){
    pair <int,int> array[n];
    for(int i=0;i<n;i++){
        array[i].first = s[i];
        array[i].second = f[i];
    }
    sort(array,array+n,compare);
    int i = 0;
    cout<<array[i].first<<" "<<array[i].second<<endl;
    for(int j=1;j<n;j++){
        if(array[i].second <= array[j].first){
            cout<<array[j].first<<" "<<array[j].second<<endl;
            i=j;
        }
    }
}

int main(){
    int s[] =  { 3, 8, 0, 1, 5, 5};
    int f[] =  { 4, 9, 6, 2, 7, 9};
    int n = sizeof(s)/sizeof(s[0]);
    printMaxActivities(s, f, n);
    return 0;
}
