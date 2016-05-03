#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define SIZE 4

void ReferencePage(deque<int> &q,unordered_map<int,deque<int>::iterator> &hash, int pageNumber){
    if(hash.count(pageNumber)==0){
        if(q.size	()==SIZE){
            hash.erase(q.back());
            q.pop_back();
        }
        q.push_front(pageNumber);
        hash[pageNumber] = q.begin();
    }
    else{
        deque<int>::iterator it = hash[pageNumber];
        if(it!=q.begin()){
            q.erase(it);
            q.push_front(pageNumber);
            hash[pageNumber] = q.begin();
        }
    }
}

void printQueue(deque<int> q){
	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop_front();
	}
}

int main(){
    deque<int> q;
	unordered_map < int,deque<int>::iterator > hash;
    ReferencePage( q, hash, 1);
    ReferencePage( q, hash, 2);
    ReferencePage( q, hash, 3);
    ReferencePage( q, hash, 1);
    ReferencePage( q, hash, 4);
    ReferencePage( q, hash, 5);
    printQueue(q);
    return 0;
}
