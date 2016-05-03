#include <iostream>
using namespace std;
#include <stack>

int lisR(int arr[],int n,int *max){
    if(n==1){
        return 1;
    }
    else{
        int temp_max=1;
        int imax;
        for(int i=0;i<n-1;i++){
            imax = lisR(arr,i+1,max);
            if(imax > *max){
                *max = imax;
            }
            if(arr[i] < arr[n-1] && imax >=temp_max){
               temp_max = imax + 1;
            }
        }
        return temp_max;
    }
}

int lisDP(int arr[],int n){
    int L[n];
    for(int i=0;i<n;i++){
        L[i]=1;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j] && L[i]<L[j]+1){
                L[i]=L[j]+1;
            }
        }
    }
    int temp=1;
    for(int i=0;i<n;i++){
        if(L[i]>temp){
            temp=L[i];
        }
    }
    int max=L[0],x=0;
    for(int i=1;i<n;i++){
        if(L[i]>max){
            max = L[i];
            x = i;
        }
    }
    stack <int > stk;
    for(int i=x-1;i>=0;i--){
        if(L[i]==max){
            cout<<L[i]<<endl;
            stk.push(arr[i]);
            max--;
        }
    }
    while(!stk.empty()){
        cout<<stk.top()<<" ";
        stk.pop();
    }
    cout<<endl;
    return temp;
}

int main() {
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 1 };;
    int n = sizeof(arr)/sizeof(arr[0]);
    int max=1;
    lisR( arr, n , &max);
    cout<<"Length of LIS is "<<max<<endl;
    cout<<"Length of LIS is "<<lisDP( arr, n )<<endl;
    return 0;
}
