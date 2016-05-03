#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int findXOR(int a,int b){
    int ans = 0;
    for(int i=31;i>=0;i--){
        int x= 1<<i;
        int bit = (a&x) & (b&x) ? 0 : (a&x)|(b&x);
        ans<<1;
        ans|=bit;
    }
    return ans;
}

int main() {
    cout<<findXOR(3,5);
    return 0;
}
