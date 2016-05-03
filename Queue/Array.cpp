#include <iostream>
#include <climits>
using namespace std;

struct Queue{
    int *arr;
    int size;
    int cap;
    int front;
    int rear;
};

Queue* createQueue(int cap){
    Queue *q = new Queue;
    q->cap = cap;
    q->arr = new int[cap];
    q->size = 0;
    q->rear = cap-1;
    q->front = 0;
    return q;
}

int full(Queue* q){
    return (q->size == q->cap);
}

void enqueue(Queue* q,int node){
    if(full(q)){
        cout<<"Cannot enqueue. Queue full."<<endl;
        return;
    }
    q->rear = (q->rear + 1)%q->cap;
    q->arr[q->rear] = node;
    q->size++;
    cout<<node<<" enqueued in queue."<<endl;
}

int empty(Queue* q){
    return (q->size == 0);
}

int dequeue(Queue* q){
    if(empty(q)){
        cout<<"Cannot dequeue. Queue empty."<<endl;
        return INT_MIN;
    }
    int item = q->arr[q->front];
    q->front = (q->front + 1)%q->cap;
    q->size--;
    return item;
}

int front(Queue* q){
    if(empty(q)){
        return INT_MIN;
    }
    return q->arr[q->front];
}

int rear(Queue* q){
    if(empty(q)){
        return INT_MIN;
    }
    return q->arr[q->rear];
}

int main(){
    Queue* queue = createQueue(1000);
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    cout<<dequeue(queue)<<" dequeued from queue"<<endl;
    cout<<"Front item is "<<front(queue)<<endl;
    cout<<"Rear item is "<<rear(queue)<<endl;
    return 0;
}
