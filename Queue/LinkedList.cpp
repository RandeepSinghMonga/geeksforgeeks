#include <iostream>
#include <climits>
using namespace std;

struct node{
    int data;
    node *next;
};

struct Queue{
    node *front,*rear;
};

node* createNode(int x){
    node *newNode = new node;
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

int empty(Queue *q){
    if(q->front == NULL && q->rear ==NULL){
        return 1;
    }
    return 0;
}

void enQueue(Queue* q,int x){
    node *newNode = createNode(x);
    if(empty(q)){
        q->front = newNode;
        q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

node* deQueue(Queue* q){
    if(empty(q)){
        return NULL;
    }
    node *temp = q->front;
    if(q->front == q->rear){
        q->rear =  NULL;
    }
    q->front = q->front->next;
    return temp;
}

Queue* createQueue(){
    Queue *q = new Queue;
    q->front = NULL;
    q->rear = NULL;
    return q;
}

int main(){
    struct Queue *q = createQueue();
    enQueue(q, 10);
    enQueue(q, 20);
    deQueue(q);
    deQueue(q);
    enQueue(q, 30);
    enQueue(q, 40);
    enQueue(q, 50);
    struct node *n = deQueue(q);
    if (n != NULL)
      cout<<"Dequeued item is "<<n->data;
    return 0;
}
