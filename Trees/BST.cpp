#include <iostream>
#include <cstdlib>
#include <climits>
using namespace std;

struct node{
    int data;
    struct node *left, *right;
};

node* insert(node *root,int num){
    if(root==NULL){
        node *root = new node;
        root->data = num;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else if(root->data <= num){
        root->right = insert(root->right,num);
    }
    else{
        root->left = insert(root->left,num);
    }
}

void inorderTraversal(node *root){
    if(root==NULL)
        return;
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

void search(node *root,int num){
    if(root==NULL){
        cout<<"Not Found"<<endl;
    }
    else if(root->data == num){
        cout<<"Found"<<endl;
    }
    else if(root->data < num){
        search(root->right,num);
    }
    else{
        search(root->left,num);
    }
}

node* minValueNode(node *root){
    if(root == NULL)
        return root;
    node *min;
    min = root;
    while(min!=NULL){
        min = min->left;
    }
    return min;
}

node* deleteNode(node* root,int num){
    if(root->data == NULL){
        return root;
    }
    if(root->data < num){
        root->right = deleteNode(root->right,num);
    }
    else if(root->data > num){
        root->left = deleteNode(root->left,num);
    }
    else{
        if(root->left == NULL){
            node *temp = root->right;
            free(root);
            return temp;
        }
        if(root->right == NULL){
            node *temp = root->right;
            free(root);
            return temp;
        }
        node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right,temp->data);
    }
    return root;
}

node *predecessor(node *root){
    if(root->left == NULL)return root;
    node *temp = root->left;
    while(temp->right!=NULL){
        temp = temp->right;
    }
    return temp;
}

node *successor(node* root){
    if(root->right == NULL)return root;
    node *temp = root->right;
    while(temp->right!=NULL){
        temp = temp->left;
    }
    return temp;
}

bool checkBST(node *root, int min, int max){
    if(root==NULL)return true;
    if(root->data < min || root->data > max)
        return false;
    return checkBST(root->left,min,root->data-1) && checkBST(root->right,root->data+1,max);
}

node *leastCommonAncestor(node *root,int one, int two){

}

int main(){
    node *root = new node;
    root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    inorderTraversal(root);cout<<endl;
    search(root,40);
    search(root,10);
    cout<<"Deleting 40"<<endl;
    deleteNode(root,40);
    inorderTraversal(root);cout<<endl;
    if(checkBST(root,INT_MIN,INT_MAX))cout<<"Yes, its a BST";
    else cout<<"Not a BST";
    //leastCommonAncestor(node *root,60,80);
    return 0;
}
