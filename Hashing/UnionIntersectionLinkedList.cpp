#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void unionList(list<int> list1,list<int> list2){
    map<int,int> hash;
    list <int> unionlist;
    list <int> intersectionlist;
    list<int>::iterator it;

    for(it=list2.begin();it!=list2.end();it++){
        hash[*it]=1;
        unionlist.push_back(*it);
    }

    for(it=list1.begin();it!=list1.end();it++){
        if(!hash[*it]){
            hash[*it]=1;
            unionlist.push_back(*it);
        }
        else{
            intersectionlist.push_back(*it);
        }
    }

    cout<<"Union List"<<endl;
    for(it=unionlist.begin();it!=unionlist.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    cout<<"Intersection List"<<endl;
    for(it=intersectionlist.begin();it!=intersectionlist.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}

void intersectionList(list<int> list1,list<int> list2){

}

int main(){
    int arr1[] = {20,4,15,10};
    list <int> list1(arr1,arr1+sizeof(arr1)/sizeof(arr1[0]));
    int arr2[] = {10,2,4,8};
    list <int> list2(arr2,arr2+sizeof(arr2)/sizeof(arr2[0]));
    unionList(list1,list2);
    intersectionList(list1,list2);
}
