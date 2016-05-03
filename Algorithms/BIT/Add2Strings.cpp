#include <iostream>
using namespace std;
#include <bits/stdc++.h>

string addBitStrings(string str1,string str2){
    string ans;
    reverse(str1.begin(),str1.end());
    reverse(str2.begin(),str2.end());
    int x = max(str1.size(),str2.size());
    str1.resize(x,'0');
    str2.resize(x,'0');
    int carry=0;
    ans.resize(x);
    for(int i=0;i<x;i++){
        ans[i] = (((str1[i]-'0')+(str2[i]-'0')+carry)%2+'0');
        carry = ((str1[i]-'0')+(str2[i]-'0')+carry)/2;
    }
    if(carry){
        ans.push_back('1');
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    string str1 = "1100011";
    string str2 = "1000000";
    cout << "Sum is " << addBitStrings(str1, str2);
    return 0;
}
