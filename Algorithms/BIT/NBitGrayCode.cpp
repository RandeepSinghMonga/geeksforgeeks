#include <iostream>
using namespace std;
#include <bits/stdc++.h>

vector<string> generateGrayarr(int n){
    vector<string> ans;
    if(n<=0){
        return ans;
    }
    ans.push_back("0");
    ans.push_back("1");
    for(int i=2;i<=n;i++){
        int j=ans.size()-1;
        while(j>=0){
            ans.push_back(ans[j]);
            j--;
        }
        for(j=0;j<ans.size()/2;j++){
            ans[j].insert(0,"0");
        }
        for(j=ans.size()/2;j<ans.size();j++){
            ans[j].insert(0,"1");
        }
    }
    return ans;
}

int main(){
    vector<string> ans = generateGrayarr(4);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}
