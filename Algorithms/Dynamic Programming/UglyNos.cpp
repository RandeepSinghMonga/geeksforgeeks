#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int min(int a,int b){
    return a<b?a:b;
}

int getNthUglyNo(int n){
    int dp[n];
    dp[0]=1;
    int i2=0,i3=0,i5=0;
    int two=dp[i2]*2;
    int three=dp[i3]*3;
    int five=dp[i5]*5;
    for(int i=1;i<n;i++){
        dp[i]=min(min(two,three),five);
        if(dp[i]==two){
            i2+=1;
            two=dp[i2]*2;
        }
        if(dp[i]==three){
            i3+=1;
            three=dp[i3]*3;
        }
        if(dp[i]==five){
            i5+=1;
            five=dp[i5]*5;
        }
    }
    return dp[n-1];
}

int main(){
    unsigned no = getNthUglyNo(150);
    cout<<"150th ugly no. is "<<no;
    return 0;
}
