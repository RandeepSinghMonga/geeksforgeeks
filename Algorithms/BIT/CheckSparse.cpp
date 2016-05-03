#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int checkSparse(int num){
    int flag=0;
    for(int i=0;i<32;i++){
        if(num & (1<<i)){
            if(flag==1){
                return 0;
            }
            flag=1;
        }
        else{
            flag=0;
        }
    }
    return 1;
}

int main(){
    cout << checkSparse(72) << endl;
    cout << checkSparse(12) << endl;
    cout << checkSparse(2) << endl;
    cout << checkSparse(3) << endl;
    return 0;
}
