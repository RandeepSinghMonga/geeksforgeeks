#include <iostream>
using namespace std;
#include <cstring>

int min(int a,int b,int c){
    if(a<b && a<c){
        return a;
    }
    else if(b<c){
        return b;
    }
    else{
        return c;
    }
}

int EditDistanceR(string X,string Y,int n,int m){
    if(m==0){
        return n;
    }
    else if(n==0){
        return m;
    }
    else{
        return min(
                   EditDistanceR(X,Y,n-1,m)+1,
                   EditDistanceR(X,Y,n,m-1)+1,
                   EditDistanceR(X,Y,n-1,m-1)+(X[n-1]!=Y[m-1])
                   );
    }
}

int EditDistanceDP(string X,string Y,int n,int m){
    int arr[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0){
                arr[i][j]=j;
            }
            else if(j==0){
                arr[i][j]=i;
            }
            else{
                arr[i][j]=min(arr[i-1][j]+1,arr[i][j-1]+1,arr[i-1][j-1]+(X[i-1]!=Y[j-1]));
            }
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout<<arr[i][j];
        }
        cout<<endl;
    }
    return arr[n][m];
}

int main(){
    string X = "sunday";
    string Y = "saturday";
    int n = X.size();
    int m = Y.size();
    cout<<EditDistanceDP(X,Y,n,m)<<endl;
    cout<<EditDistanceR(X,Y,n,m);
    return 0;
}
