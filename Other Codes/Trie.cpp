#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class node{
public:
	char val;
	bool last;
	int count;
	map<char,node*> children;
	node(){
		val = ' ';
		last = false;
		count=0;
	}
};

class trie{
public:
	node *root;
	trie();
	void addWord(string str);
	void deleteWord(string str);
	int deleteTrieRec(node* curr,string str);
	int searchWord(string str);
};

trie::trie(){
	root=new node();
}

void trie::addWord(string str){
	node* curr = root;
	for(int i=0;i<str.size();i++){
		if(curr->children[str[i]]==NULL){
			node* temp = new node();
			temp->val = str[i];
			curr->children[str[i]] = temp;
		}
		curr = curr->children[str[i]];
		curr->count++;
	}
	curr->last = true;
}

int trie::searchWord(string str){
	node* curr = root;
	for(int i=0;i<str.size();i++){
		if(curr->children[str[i]]==NULL){
			return 0;
		}
		curr = curr->children[str[i]];
	}
	if(!curr->last){
		return 0;
	}
	return 1;
}

int trie::deleteTrieRec(node *curr,string str){
	if(str.size()==0){
		for(int i=0;i<curr->children.size();i++){
			if(curr->children[i]!=NULL){
				return 0;
			}
		}
		return 1;
	}
	curr = curr->children[str[0]];
	if(curr==NULL){
		return 0;
	}
	if(!deleteTrieRec(curr,&str[1])){
		return 0;
	}
	if(str.size()>1 && curr->last){
		curr->children[str[1]] = NULL;
		return 0;
	}
	free(curr);
	return 1;
}

void trie::deleteWord(string str){
	deleteTrieRec(root,str);
}

void printTrie(string prefix,node* curr){
	if(curr->last){
		cout<<prefix<<endl;
	}
	for(int i=0;i<curr->children.size();i++){
		if(curr->children[i]!=NULL){
			prefix.push_back((curr->children[i])->val);
			printTrie(prefix,curr->children[i]);
			prefix.pop_back();
		}
	}
}

string findPrefix(node *root, string str){
    node *curr = root;
    int index=0;
    for(int i=0;i<str.size();i++){
        curr = curr->children[str[i]];
        if(curr->count==1){
            index=i;
            break;
        }
    }
    return str.substr(0,index+1);
}

int main(){
    //string keys[] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
    string keys[] = {"zebra","dot","dove","dog"};
    trie* t = new trie();
    for(int i = 0; i < sizeof(keys)/sizeof(keys[0]); i++){
        t->addWord(keys[i]);
    }
    /*cout<<t->searchWord("the")<<endl;
    cout<<t->searchWord("these")<<endl;
    printTrie("",t->root);
    t->deleteWord("there");
    printTrie("",t->root);
    cout<<t->searchWord("there")<<endl;
    */
    for(int i=0;i<sizeof(keys)/sizeof(keys[0]);i++){
        cout<<findPrefix(t->root,keys[i])<<endl;
    }
    return 0;
}
//http://ideone.com/g7EAJN
