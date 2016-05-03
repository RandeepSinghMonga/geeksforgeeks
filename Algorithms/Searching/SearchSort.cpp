#include <iostream>
#include <cstdlib>
using namespace std;

int binarySearch(int arr[],int low,int high,int num){
    if(low>high)return -1;
    int mid = (low+high)/2;
    if(arr[mid] == num)return mid;
    else if(arr[mid] > num)return binarySearch(arr,low,mid,num);
    else return binarySearch(arr,mid+1,high,num);
}

void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min])min=j;
        }
        swap(&arr[i],&arr[min]);
    }
}

void bubbleSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j])
                swap(&arr[i],&arr[j]);
        }
    }
}

void insertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int temp = arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

void merge(int arr[],int l,int m,int r){
    int n1 = m-l+1;
    int n2 = r-m;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++){
        L[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++){
        R[i]=arr[m+1+i];
    }
    int i=l,j=0,k=0;
    while(j<n1 && k<n2){
        if(L[j]<=R[k]){
            arr[i] = L[j];
            j++;
        }
        else{
            arr[i] = R[k];
            k++;
        }
        i++;
    }
    while(j<n1){
        arr[i] = L[j];
        j++;
        i++;
    }
    while(k<n2){
        arr[i] = R[k];
        k++;
        i++;
    }
}

void mergeSort(int arr[],int l,int r){
    if(l<r){
        int mid = l+(r-l)/2;
        mergeSort(arr,l,mid);
        for(int i=l;i<=mid;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        mergeSort(arr,mid+1,r);
        for(int i=mid+1;i<=r;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        merge(arr,l,mid,r);
        for(int i=l;i<=r;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
}

struct heap{
    int *arr;
    int size;
};

void maxHeapify(heap *h,int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if(left<h->size && h->arr[left]>h->arr[largest]){
        largest = left;
    }
    if(right<h->size && h->arr[right]>h->arr[largest]){
        largest = right;
    }
    if(largest != i){
        swap(&h->arr[i],&h->arr[largest]);
        maxHeapify(h,largest);
    }
}

void heapSort(int arr[],int n){
    heap *h = new heap;
    h->arr = arr;
    h->size = n;
    for(int i=(h->size-2)/2;i>=0;i--){
        maxHeapify(h,i);
    }
    while(h->size > 1){
        swap(&h->arr[0],&h->arr[h->size-1]);
        h->size--;
        maxHeapify(h,0);
    }
}

int partition(int arr[],int l,int h){
    int x = arr[h];
    int i=0;
    for(int j=l;j<h;j++){
        if(x>=arr[j]){
            swap(&arr[i],&arr[j]);
            i++;
        }
    }
    swap(&arr[i],&arr[h]);
    return i;
}

void quickSort(int arr[],int l,int r){
    if(l<r){
        int p = partition(arr,l,r);
        quickSort(arr,l,p-1);
        quickSort(arr,p+1,r);
    }
}

int main(){
   int arr[7] = {4,2,7,3,9,6,8};
   int n = sizeof(arr)/sizeof(int);
   cout<<"index: "<<binarySearch(arr,0,n,6)<<endl;
   //selectionSort(arr,n);
   //printArray(arr,n);
   //bubbleSort(arr,n);
   //printArray(arr,n);
   //insertionSort(arr,n);
   //printArray(arr,n);
   //mergeSort(arr,0,n-1);
   //printArray(arr,n);
   //heapSort(arr,n);
   //printArray(arr,n);
   quickSort(arr,0,n-1);
   printArray(arr,n);
}
