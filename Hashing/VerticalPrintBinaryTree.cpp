#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
};

Node* newNode(int key)
{
    Node* node = new Node;
    node->data = key;
    node->left = node->right = NULL;
    return node;
}

void getVerticalOrder(Node* root,int i,map<int,vector<int> >&arr){
    if(root==NULL){
        return;
    }
    arr[i].push_back(root->data);
    getVerticalOrder(root->left,i-1,arr);
    getVerticalOrder(root->right,i+1,arr);
}

Node* printVerticalOrder(Node* root){
    map<int,vector<int> > arr;
    getVerticalOrder(root,0,arr);

    map<int,vector<int> > :: iterator it;
    for(it=arr.begin();it!=arr.end();it++){
        for(int i=0;i<it->second.size();i++){
            cout<<it->second[i]<<" ";
        }
        cout<<endl;
    }

}

int main(){
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);
    cout << "Vertical order traversal is \n";
    printVerticalOrder(root);
    return 0;
}
