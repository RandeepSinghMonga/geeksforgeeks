#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int multiplyBySevenByEight(unsigned int n){
   return ((n << 3) -n) >> 3;
}

int main(){
    unsigned int n = 15;
    cout<<multiplyBySevenByEight(n);
    return 0;
}
