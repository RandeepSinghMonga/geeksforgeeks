#include <iostream>
#include <cstdlib>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
};

node* createNode(int data){
    node *head = new node;
    head->data = data;
    head->left = NULL;
    head->right = NULL;
    return head;
}

node* insertNode(node* head,node *root){
    if(head==NULL){
        return root;
    }
    if(root==NULL){
        return head;
    }


    return head;
}

node* treeToList(node* root){
    if(root==NULL){
        return root;
    }
    node *x = treeToList(root->left);
    node *y = treeToList(root->right);
    root->left = NULL;
    root->right = NULL;
    insertNode(x,root);
    insertNode(x,y);
    return x;
}

void printList(node* head){
    node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->right;
    }
}

int main() {
    node* root = NULL;
    node* head;
    head = createNode(5);
    head->left = createNode(3);
    head->left->left = createNode(2);
    head->left->right = createNode(4);
    head->right->left = createNode(6);
    head->right->right = createNode(8);
    head = treeToList(root);
    printList(head);    /* prints: 1 2 3 4 5  */
    return(0);
}
