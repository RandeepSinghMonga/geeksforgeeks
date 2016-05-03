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

void preorderTraversal(node *head){
    if(head==NULL)return;
    cout<<head->data<<" ";
    preorderTraversal(head->left);
    preorderTraversal(head->right);
}

void postorderTraversal(node *head){
    if(head==NULL)return;
    preorderTraversal(head->left);
    preorderTraversal(head->right);
    cout<<head->data<<" ";
}

void inorderTraversal(node *head){
    if(head==NULL)return;
    preorderTraversal(head->left);
    cout<<head->data<<" ";
    preorderTraversal(head->right);
}

int sizeOfTree(node *head){
    if(head == NULL){
        return 0;
    }
    return sizeOfTree(head->left)+sizeOfTree(head->right)+1;
}

bool Identical(node *head,node *head1){
    if(head == NULL && head1 == NULL){
        return true;
    }
    if((head == NULL && head1 != NULL) && (head != NULL && head1 == NULL)){
        return false;
    }
    if(head->data == head1->data && Identical(head->left,head1->left) && Identical(head->right,head1->right)){
        return true;
    }
    return false;
}

int max(int a,int b){
    return a>b ? a : b;
}

int heightOfTree(node *head){
    if(head == NULL){
        return 0;
    }
    return max(heightOfTree(head->left),heightOfTree(head->right)) + 1;
}

void DeleteTree(node *head){
    if(head == NULL){
        return;
    }
    DeleteTree(head->left);
    DeleteTree(head->right);
    free(head);
}

void Mirror(node *head){
    if(head==NULL){
        return;
    }
    Mirror(head->left);
    Mirror(head->right);
    node *temp;
    temp = head->left;
    head->left = head->right;
    head->right = temp;
}

void printRootToLeaf(node *head,int arr[],int n){
    if(head == NULL)
        return;
    arr[n] = head->data;
    n++;
    if(head->left==NULL && head->right==NULL){
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        return;
    }
    printRootToLeaf(head->left,arr,n);
    printRootToLeaf(head->right,arr,n);
    return;
}

int countLeafNodes(node *head){
    if(head == NULL){
        return 0;
    }
    if(head->left == NULL && head->right == NULL){
        return 1;
    }
    return countLeafNodes(head->left) + countLeafNodes(head->right);
}

int diameterOfTree(node *head){
    if(head==NULL){
        return 0;
    }
    int largest = max(max(diameterOfTree(head->left),diameterOfTree(head->right)),1+heightOfTree(head->left)+heightOfTree(head->right));
    return largest;
}

void printGivenLevel(node* head,int i){
    if(head==NULL){
        return;
    }
    if(i==0){
        cout<<head->data;
        return;
    }
    else{
        printGivenLevel(head->left,i-1);
        printGivenLevel(head->right,i-1);
        return;
    }
}

void printLevelOrder(node *head){
    for(int i=0;i<heightOfTree(head);i++){
        printGivenLevel(head,i);
    }
    cout<<endl;
}

int ChildrenSumProperty(node *head){
    int left=0,right=0;
    if(head==NULL || head->left==NULL && head->right==NULL){
        return 1;
    }
    else{
        if(head->left!=NULL){
            left = head->left->data;
        }
        if(head->right!=NULL){
            right = head->right->data;
        }
        if(head->data == head->left->data+head->right->data
           && ChildrenSumProperty(head->left)
           && ChildrenSumProperty(head->right)
           ){
            return 1;
        }
        return 0;
    }
}

int isHeightBalanced(node* head){
    if(head==NULL)return 1;
    if(heightOfTree(head->left)-heightOfTree(head->right)<=1
       && heightOfTree(head->left)-heightOfTree(head->right)>=-1
       && isHeightBalanced(head->left)
       && isHeightBalanced(head->right)
       )
        return 1;
    return 0;
}

int main(){
    node *head = new node;
    head = createNode(1);
    head->left = createNode(2);
    head->right = createNode(3);
    cout<<"PreOrder Traversal"<<endl;
    preorderTraversal(head);cout<<endl;
    cout<<"PostOrder Traversal"<<endl;
    postorderTraversal(head);cout<<endl;
    cout<<"InOrder Traversal"<<endl;
    inorderTraversal(head);cout<<endl;
    cout<<"--------------------"<<endl;
    cout<<"Size of Tree"<<endl;
    cout<<sizeOfTree(head)<<endl;
    node *head1 = new node;
    head1 = createNode(1);
    head1->left = createNode(2);
    head1->right = createNode(3);
    if(Identical(head,head1)){
        cout<<"Identical!"<<endl;
    }
    else{
        cout<<"Not Identical!"<<endl;
    }
    cout<<"--------------------"<<endl;
    cout<<"Height of Tree"<<endl;
    cout<<heightOfTree(head)<<endl;
    cout<<"--------------------"<<endl;
    cout<<"Diameter of Tree"<<endl;
    cout<<diameterOfTree(head)<<endl;
    cout<<"--------------------"<<endl;
    cout<<"Delete Tree"<<endl;
    DeleteTree(head1);
    cout<<"--------------------"<<endl;
    cout<<"Mirror Tree"<<endl;
    Mirror(head);
    inorderTraversal(head);cout<<endl;
    cout<<"--------------------"<<endl;
    cout<<"Printing Root To Leaf"<<endl;
    int arr[100];
    printRootToLeaf(head,arr,0);
    cout<<"--------------------"<<endl;
    cout<<"Counting leaf Nodes"<<endl;
    cout<<countLeafNodes(head)<<endl;
    cout<<"--------------------"<<endl;
    cout<<"Level Order Traversal"<<endl;
    printLevelOrder(head);//For spiral just have a flag
    cout<<"--------------------"<<endl;
    cout<<"Children Sum Property"<<endl;
    if(ChildrenSumProperty(head)){
        cout<<"Children Sum Property holds"<<endl;
    }
    else{
        cout<<"Children Sum Property doesn't hold"<<endl;
    }
    cout<<"--------------------"<<endl;
    cout<<"Height Balanced"<<endl;
    if(isHeightBalanced(head)){
        cout<<"Tree is height balanced"<<endl;
    }
    else{
        cout<<"Tree is not height balanced"<<endl;
    }
    cout<<"--------------------"<<endl;
    cout<<"Convert to Child Sum Property"<<endl;
    convertChildSumProperty(head);

    return 0;
}
