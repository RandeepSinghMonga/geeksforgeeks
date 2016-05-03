#include <iostream>
#include <cstdlib>
#include <climits>
using namespace std;

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = *a;
}

class MinHeap{
private:
    int *arr;
    int capacity;
    int size;
public:
    int parent(int i){
        return (i-1)/2;
    }
    int left(int i){
        return 2*i;
    }
    int right(int i){
        return 2*i+1;
    }
    int getMin(){
        return arr[0];
    }
    MinHeap(int capacity);
    void minHeapify(int i);
    void decreaseKey(int i,int value);
    int extractMin();
    void deleteKey(int i);
    void insertKey(int k);
};

MinHeap::MinHeap(int cap){
    size = 0;
    capacity = cap;
    arr = new int[cap];
}

void MinHeap::minHeapify(int i){
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if(l<size && arr[l]<arr[i])
        smallest = l;
    if(r<size && arr[r]<arr[i])
        smallest = r;
    if(smallest != i){
        swap(&arr[i],&arr[smallest]);
        minHeapify(smallest);
    }
}

void MinHeap::decreaseKey(int i,int value){
    arr[i] = value;
    while(i!=0 && arr[parent(i)] > arr[i]){
        swap(&arr[parent(i)],&arr[i]);
        i = parent(i);
    }
}

int MinHeap::extractMin(){
    if(size<=0){
        return INT_MAX;
    }
    if(size == 1){
        size--;
        return arr[0];
    }
    int ret = arr[0];
    arr[0] = arr[size - 1];
    size--;
    minHeapify(0);
    return ret;
}

void MinHeap::deleteKey(int i){
    arr[i] = arr[size - 1];
    size--;
    minHeapify(i);
}

void MinHeap::insertKey(int value){
    size++;
    arr[size-1] = value;
    int i = size-1;
    while(arr[parent(i)] > arr[i]){
        swap(&arr[parent(i)],&arr[i]);
        i = parent(i);
    }
}

int main(){
    MinHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    cout << h.extractMin() << " ";
    cout << h.getMin() << " ";
    h.decreaseKey(2, 1);
    cout << h.getMin();
    return 0;
}
