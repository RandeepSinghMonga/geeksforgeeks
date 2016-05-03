#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Node{
public:
	unordered_map<char,Node*> children;
	int count;
	string str;
	Node(){
		count = 0;
		str = "";
	}
};

class Trie{
public:
	Node *root = new Node();
	int addWord(string str){
		Node *curr = root;
		for(int i=0;i<str.size();i++){
			if(!curr->children[str[i]]){
				Node *newNode = new Node();
				curr->children[str[i]] = newNode;
			}
			curr = curr->children[str[i]];
		}
		if(curr->count==0){
			curr->str = str;
		}
		curr->count++;
		return curr->count;
	}
};

void Add(Node *curr,priority_queue<pair<int,string>>&pq){
	if(curr==NULL){
		return;
	}
	if(curr->count > 0){
		pq.push(make_pair(curr->count,curr->str));
	}
	if(curr->children.size()==0){
		return;
	}
	for(int i=0;i<curr->children.size();i++){
		Add(curr->children[i],pq);
	}
}

void printKMostFreq(vector<string> vec,int k){
	priority_queue<pair<int,string>> pq;
	Trie *t = new Trie();
	for(int i=0;i<vec.size();i++){
		t->addWord(vec[i]);
	}
	Add(t->root,pq);
	for(int i=0;i<k;i++){
		cout<<pq.top().second<<" ";
		pq.pop();
	}
}

int main(){
    int k = 5;
    string S = "Welcome to the world of Geeks This portal has been created to provide well written well thought and well explained solutions for selected questions If you like Geeks for Geeks and would like to contribute here is your chance You can write article and mail your article to contribute at geeksforgeeks org See your article appearing on the Geeks for Geeks main page and help thousands of other Geeks";
    vector<string> vec;
    int i=0,j=0;
    while(j<S.size()){
    	while(j<S.size() && S[j]!=' '){
    		j++;
    	}
    	vec.push_back(S.substr(i,j-i));
    	i=j+1;
    	j=i;
    }
    printKMostFreq(vec, 5);
    return 0;
}
