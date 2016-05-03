#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int gcd(int a,int b){
    if(b==0  || a==b){
        return a;
    }
    if(a==0){
        return b;
    }
    if((a&1)==0 && (b&1)==0){
        return gcd(a>>1,b>>1)<<1;
    }
    if((a&1)==1 && (b&1)==0){
        return gcd(a,b>>1);
    }
    if((a&1)==0 && (b&1)==1){
        return gcd(a>>1,b);
    }
    return (a>b)?gcd(a-b,b):gcd(a,b-a);
}

int main(){
    cout<<gcd(45,15)<<endl;
    return 0;
}
