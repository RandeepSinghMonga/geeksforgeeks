#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

struct tree{
    int data;
    int count;
    tree *left,*right;
};

void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void checkPair(int arr[],int n,int sum){
    sort(arr,arr+n);
    int i=0,j=n-1;
    while(i!=j){
        if(arr[i]+arr[j] == sum){
            cout<<arr[i]<<" "<<arr[j]<<endl;
            i++;
            j--;
        }
        else if(arr[i]+arr[j] < sum){
            i++;
        }
        else{
            j--;
        }
    }
}

int majorityElementS(int arr[],int n){
    sort(arr,arr+n);
    int count;
    int now;
    for(int i=0;i<n;){
        count = 0;
        now = arr[i];
        while(arr[i]==now){
            i++;
            count++;
        }
        if(count>n/2)return arr[i-1];
    }
    return -1;
}

tree* insertBST(tree* root,int num){
    if(root == NULL){
        tree* node = new tree;
        node->data = num;
        node->count = 1;
        node->left = NULL;
        node->right = NULL;
        root = node;

    }
    else if(root->data == num){
        root->count ++;
    }
    else if(root->data < num){
        root->right = insertBST(root->right,num);
    }
    else{
        root->left = insertBST(root->left,num);
    }
    return root;
}


void inorderPrint(tree* root){
    if(root == NULL)return;
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}

int findMajority(tree* root,int n){
    if(root == NULL)return -1;
    if(root->count > n/2){
        return root->data;
    }
    if(findMajority(root->left,n) != -1)return findMajority(root->left,n);
    else if(findMajority(root->right,n) != -1)return findMajority(root->right,n);
    else return -1;
}

int majorityElementT(int arr[],int n){
    tree *root = new tree;
    root = NULL;
    for(int i=0;i<n;i++){
        if(i==0)root = insertBST(root,arr[i]);
        insertBST(root,arr[i]);
    }
    cout<<"Printing the BST formed"<<endl;
    inorderPrint(root);cout<<endl;
    return findMajority(root,n);
}

void reverseArray(int arr[],int n){
    int temp;
    for(int i=0;i<n/2;i++){
        temp = arr[i];
        arr[i] = arr[n-1-i];
        arr[n-1-i] = temp;
    }
}

int oddTimes(int arr[],int n){
    int res = 0;
    for(int i=0;i<n;i++){
        res = res ^ arr[i];
    }
    return res;
}

int majorityElementMV(int arr[],int n){
    int index = 0;
    int count = 1;
    for(int i=1;i<n;i++){
        if(arr[i]==arr[index]){
            count++;
        }
        else{
            count--;
        }
        if(count==0){
            index = i;
            count = 1;
        }
    }
    count=0;
    for(int i=0;i<n;i++){
        if(arr[i]==arr[index]){
            count++;
        }
    }
    if(count>n/2)return arr[index];
    else return -1;
}

int LargestSumContiguousSubarray(int arr[],int n){
    int max=0;
    int sum=0,i=0;
    while(i<n){
        sum = (arr[i]>sum + arr[i]) ? arr[i] : sum+arr[i];
        max = max > sum ? max : sum;
        i++;
    }
    return max;
}

int missingNumber(int arr[],int n){
    int sum = (n+1)*(n+2)/2;
    for(int i=0;i<n;i++){
        sum-=arr[i];
    }
    return sum;
}

int main(){
    int arr[]={1, 2, 4 ,6, 3, 7, 8};
    int n = sizeof(arr)/sizeof(int);
    cout<<"Given an array A[] and a number x, check for pair in A[] with sum as x"<<endl;
    checkPair(arr,n,9);
    cout<<"-------------------------------------------------------------------------"<<endl;
    cout<<"Majority Element"<<endl;
    cout<<majorityElementS(arr,n)<<endl;//SortAndTry
    cout<<majorityElementT(arr,n)<<endl;//BST
    cout<<majorityElementMV(arr,5)<<endl;//Moore’s Voting Algorithm
    cout<<"-------------------------------------------------------------------------"<<endl;
    cout<<"Number Occurring Odd Number of Times"<<endl;
    cout<<oddTimes(arr,n)<<" occurs odd times"<<endl;
    cout<<"-------------------------------------------------------------------------"<<endl;
    cout<<"Reverse an array"<<endl;
    printArray(arr,n);
    reverseArray(arr,n);
    printArray(arr,n);
    cout<<"-------------------------------------------------------------------------"<<endl;
    cout<<"Largest Sum Contiguous Subarray"<<endl;
    cout<<LargestSumContiguousSubarray(arr,n)<<endl;
    cout<<"-------------------------------------------------------------------------"<<endl;
    cout<<"Missing Number"<<endl;
    cout<<missingNumber(arr,n)<<endl;
    cout<<"-------------------------------------------------------------------------"<<endl;
    cout<<"Search in a Pivote Sorted Array"<<endl;
    //cout<<pivotSearch(arr,n)<<endl;
    cout<<"-------------------------------------------------------------------------"<<endl;
}
