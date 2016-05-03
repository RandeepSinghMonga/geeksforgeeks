#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int max(int a,int b){
    return a>b?a:b;
}

int longestPalSubstrDP(char str[],int n){
    int pal[n][n];
    int len=0;
    int start=0;
    for(int x=1;x<=n;x++){
        for(int i=0;i<n-x+1;i++){
            int j=x+i-1;
            if(i==j){
                pal[i][i]=1;
                if(x>len){
                    start=i;
                    len=x;
                }
            }
            else if(i==j-1){
                pal[i][j]=(str[i]==str[j]);
                if(x>len){
                    start=i;
                    len=x;
                }
            }
            else if(pal[i+1][j-1] && (str[i]==str[j])){
                pal[i][j]=1;
                if(x>len){
                    start=i;
                    len=x;
                }
            }
            else{
                pal[i][j]=0;
            }
        }
    }
    for(int i=start;i<start+len;i++){
        cout<<str[i];
    }
    cout<<endl;
    return len;
}

int main()
{
    char str[] = "forgeeksskeegfor";
    int n = strlen(str);
    cout<<"Length is: "<<longestPalSubstrDP(str,n);
    return 0;
}
