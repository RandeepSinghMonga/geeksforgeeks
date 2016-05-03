#include <iostream>
using namespace std;

struct Stack{
    int *arr;
    int size;
    int cap;
};

int isEmpty(Stack* stk){
    if(stk->size == 0)
        return 1;
    return 0;
}

int top(Stack* stk){
    if(isEmpty(stk)){
        cout<<"Stack is Empty"<<endl;
        return -1;
    }
    return stk->arr[stk->size - 1];
}

int pop(Stack* stk){
    if(isEmpty(stk)){
        return -1;
    }
    int ret = top(stk);
    stk->size--;
    return ret;
}

void push(Stack *stk, int i){
    if(stk->size == stk->cap) return;
    stk->size ++;
    stk->arr[stk->size-1] = i;
    return;
}

Stack* createStack(int cap){
    Stack *stk = new Stack;
    stk->arr = new int[cap];
    stk->cap = cap;
    stk->size = 0;
    return stk;
}

int main(){
    struct Stack *stack = createStack(100);
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    cout<<pop(stack)<<" popped from stack\n"<<endl;
    cout<<"Top item is "<<top(stack)<<endl;
    return 0;
}
