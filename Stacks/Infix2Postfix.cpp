#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int isOperator(char ch){
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^'){
        return 1;
    }
    return 0;
}

int precedence(char ch){
    switch(ch){
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    }
    return -1;
}

char* infixToPostfix(char expr[]){
    int n = strlen(expr);
    stack <char> stk;
    int k=-1;
    for(int i=0;i<n;i++){
        if(isOperator(expr[i])){
            while(!stk.empty() && precedence(expr[i]) <= precedence(stk.top())){
                expr[++k]=stk.top();
                stk.pop();
            }
           stk.push(expr[i]);
        }
        else if(expr[i]=='('){
           stk.push(expr[i]);
        }
        else if(expr[i]==')'){
            while(stk.top()!='('){
                expr[++k]=stk.top();
                stk.pop();
            }
            stk.pop();
        }
        else{
            expr[++k]=expr[i];
        }
    }
    while(!stk.empty()){
        expr[++k]=stk.top();
        stk.pop();
    }
    expr[++k]='\0';
    return expr;
}

int isDigit(char ch){
    if(ch>='0' && ch <='9')
        return 1;
    return 0;
}

int evaluate(char expr[]){
    stack <int> stk;
    int n = strlen(expr);
    for(int i=0;i<n;i++){
        if(isDigit(expr[i])){
            stk.push((int)(expr[i]-'0'));
        }
        else{
            int a = stk.top();stk.pop();
            int b = stk.top();stk.pop();
            switch (expr[i]){
                case '+':
                    stk.push(a+b);break;
                case '-':
                    stk.push(b-a);break;
                case '*':
                    stk.push(a*b);break;
                case '/':
                    stk.push(a/b);break;
            }
        }
    }
    return stk.top();
}

char* reverse(char expr[]){
    stack <char> stk;
    for(int i=0;i<strlen(expr);i++){
        stk.push(expr[i]);
    }
    int i=0;
    while(!stk.empty()){
        expr[i++] = stk.top();
        stk.pop();
    }
    return expr;
}

int balancedParanthesis(char exp[]){
    stack <char> stk;
    for(int i=0;i<strlen(exp);i++){
        if(exp[i]=='('){
            stk.push(exp[i]);
        }
        else if(exp[i]==')'){
            if(stk.empty())
                return 0;
            else if(stk.top() == '(')
                stk.pop();
        }
    }
    if(!stk.empty())
        return 0;
    return 1;
}

void nextGreaterElement(int arr[],int n){
    stack <int> stk;
    for(int i=0;i<n;i++){
        while(!stk.empty() && arr[i] > stk.top()){
            cout<<stk.top()<<" : "<<arr[i]<<endl;
            stk.pop();
        }
        stk.push(arr[i]);
    }
    while(!stk.empty()){
        cout<<stk.top()<<" : -1"<<endl;
        stk.pop();
    }
}

int main(){
    char exp[] = "2+3*1-9";
    cout<<infixToPostfix(exp)<<endl;
    cout<<evaluate(exp)<<endl;
    cout<<reverse(exp)<<endl;
    char par[] = "(()())";
    if(balancedParanthesis(exp))
        cout<<"Balanced"<<endl;
    int arr[] = {4, 5, 2, 25};
    nextGreaterElement(arr,sizeof(arr)/sizeof(arr[0]));
    return 0;
}
