#include <iostream>
#include <climits>
using namespace std;

int max(int a,int b){
    return a>b?a:b;
}

int eggDropR(int n,int f){
    if(f==1||f==0){
        return f;
    }
    if(n==1){
        return f;
    }
    int min = INT_MAX;
    int ans;
    for(int i=1;i<=f;i++){
        ans = max(eggDropR(n-1,i-1),eggDropR(n,f-i));
        if(ans < min){
            min = ans;
        }
    }
    return min+1;
}

int eggDropDP(int n,int f){
    int arr[n+1][f+1];
    for(int i=0;i<=n;i++){
        arr[i][0]=0;
        arr[i][1]=1;
    }
    for(int i=1;i<=f;i++){
        arr[1][i]=i;
    }
    for(int i=2;i<=n;i++){
        for(int j=2;j<=f;j++){
            arr[i][j] = INT_MAX;
            int ans;
            for(int k=1;k<=j;k++){
                ans = 1 + max(arr[i-1][k-1],arr[i][j-k]);
                if(ans < arr[i][j]){
                    arr[i][j] = ans;
                }
            }
        }
    }
    return arr[n][f];
}

int main(){
    int n = 2, f = 36;
    cout<<eggDropR(2, 10)<<endl;
    cout<<eggDropDP(2, 36)<<endl;
    return 0;
}
