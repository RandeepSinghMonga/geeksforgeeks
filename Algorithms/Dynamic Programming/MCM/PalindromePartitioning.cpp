#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int isPalindrome(char str[],int i,int j){
    int flag=1;
    while(i!=j){
        if(str[i]!=str[j]){
            flag=0;
            break;
        }
        i++;
        j--;
    }
    return flag;
}

int minPalPartionR(char str[],int i, int j){
    if(i==j){
        return 0;
    }
    else if(isPalindrome(str,i,j)){
        return 0;
    }
    else{
        int ans;
        int min = INT_MAX;
        for(int k=i;k<j;k++){
            ans = minPalPartionR(str,i,k)+minPalPartionR(str,k+1,j)+1;
            if(min>ans){
                min = ans;
            }
        }
        return min;
    }
}

int minPalPartionDP(char str[],int n){
    int cuts[n+1][n+1],pal[n+1][n+1];
    for(int i=0;i<=n;i++){
        pal[i][i]=1;
        cuts[i][i]=0;
    }
    for(int x=2;x<=n;x++){
        for(int i=0;i<=n-x;i++){
            int j=x+i-1;
            if(x==2){
                pal[i][j]= str[i]==str[j];
            }
            else{
                pal[i][j]= (str[i]==str[j]) && pal[i+1][j-1];
            }
            if(pal[i][j]){
                cuts[i][j]=0;
            }
            else{
                int temp;

                cuts[i][j]=INT_MAX;
                for(int k=i;k<j;k++){
                    temp = cuts[i][k]+cuts[k+1][j]+1;
                    if(cuts[i][j]>temp){
                        cuts[i][j]=temp;
                    }
                }
            }
        }
    }
    return cuts[0][n-1];
}

int main(){
   char str[] = "ababbbabbababa";
   cout<<"Min cuts needed for Palindrome Partitioning is "<<minPalPartionR(str,0,strlen(str)-1)<<endl;
   cout<<"Min cuts needed for Palindrome Partitioning is "<<minPalPartionDP(str,strlen(str))<<endl;
   return 0;
}
