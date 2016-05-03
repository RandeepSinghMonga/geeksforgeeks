#include <iostream>
using namespace std;

int binomialCoefficientR(int n,int k){
    if(k==0 || k==n){
        return 1;
    }
    else{
        return binomialCoefficientR(n-1,k-1)+binomialCoefficientR(n-1,k);
    }
}

int binomialCoefficientDP(int n,int k){
    int arr[n+1][k+1];
    for(int i=1;i<n+1;i++){
        arr[i][0]=1;
        arr[i][i]=1;
    }
    for(int i=2;i<n+1;i++){
        for(int j=1;j<i;j++){
            arr[i][j]=arr[i-1][j-1]+arr[i-1][j];
        }
    }
    return arr[n][k];
}

int main()
{
    int n = 7, k = 5;
    cout<<binomialCoefficientR(n, k)<<endl;
    cout<<binomialCoefficientDP(n, k)<<endl;
    return 0;
}
