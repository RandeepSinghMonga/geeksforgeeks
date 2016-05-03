#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int isPalindrome(int num){
    for(int i=0;i<16;i++){
        if((num&(1<<i)) ^ (num&(1<<(31-i)) == 1)){
            return 0;
        }
    }
    return 1;
}

int main(){
    int x = 1<<15;
    cout << isPalindrome(x) << endl;
    x = 1<<31 + 1;
    cout << isPalindrome(x) << endl;

}
