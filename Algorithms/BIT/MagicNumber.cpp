#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int nthMagicNo(int n){
    int pow = 1;
    int ans = 0;
    while(n){
        pow*=5;
        if(n&1){
            ans += pow;
        }
        n>>=1;
    }
    return ans;
}

int main(){
    int n = 5;
    cout << "n'th magic number is " << nthMagicNo(n) << endl;
    return 0;
}
