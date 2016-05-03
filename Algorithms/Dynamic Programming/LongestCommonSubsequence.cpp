#include <iostream>
#include <cstring>
using namespace std;

int max(int a,int b){
    return a>b?a:b;
}

int lcsR(char *x,int n,char *y,int m){
    if(n==0 || m==0){
        return 0;
    }
    if(x[n-1]==y[m-1]){
        return 1+lcsR(x,n-1,y,m-1);
    }
    return max(lcsR(x,n,y,m-1),lcsR(x,n-1,y,m));
}

int lcsDP(char *X,int n,char *Y,int m){
    int arr[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0){
                arr[i][j] = 0;
            }
            else if(X[i-1]==Y[j-1]){
                arr[i][j]=arr[i-1][j-1]+1;
            }
            else{
                arr[i][j] = max(arr[i-1][j],arr[i][j-1]);
            }
            cout<<arr[i][j];
        }
        cout<<endl;
    }
    int index = arr[n][m];
    char lcs[index];
    int i=n,j=m;
    lcs[index]='\0';
    while(i>0 && j>0){
        if(X[i-1]==Y[j-1]){
            lcs[index-1]=X[i-1];
            index--;
            i--;
            j--;
        }
        else{
            if(arr[i][j-1]<arr[i-1][j]){
                i--;
            }
            else{
                j--;
            }
        }
    }
    cout<<lcs<<endl;
    return arr[n][m];
}

int main(){
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    int m = strlen(X);
    int n = strlen(Y);
    cout<<"Length of LCS is "<<lcsR(X,m,Y,n)<<endl;
    cout<<"Length of LCS is "<<lcsDP(X,m,Y,n)<<endl;
}
