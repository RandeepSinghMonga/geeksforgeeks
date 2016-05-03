#include <iostream>
#include <cstring>
using namespace std;

void swap(char str[],int i,int j){
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
}

void permute(char str[],int i){
    if(i==strlen(str)-1){
        cout<<str<<endl;
        return;
    }
    for(int j=i;j<strlen(str);j++){
        swap(str,i,j);
        permute(str,i+1);
        swap(str,i,j);
    }
}

int main(){
    char str[100] = "abc";
    permute(str,0);
    cout<<str;
}
