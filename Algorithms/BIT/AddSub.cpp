#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int Add(int a, int b){
    while(b!=0){
        int carry = a&b;
        a = a^b;
        b = carry<<1;
    }
    return a;
}

int Sub(int x, int y){
    while (y != 0){
        int borrow = (~x) & y;
        x = x ^ y;
        y = borrow << 1;
    }
    return x;
}

int main(){
    cout<<Add(32,15)<<endl;
    cout<<Sub(32,15)<<endl;
    return 0;
}
