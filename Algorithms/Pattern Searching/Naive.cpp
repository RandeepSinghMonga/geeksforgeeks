#include <iostream>
#include <cstring>
using namespace std;

void NaiveSearch(char pat[],char txt[]){
    for(int i=0;i<strlen(txt);i++){
        int k = i;
        int flag=1;
        for(int j=0;j<strlen(pat);j++){
            if(txt[k]!=pat[j]){
                flag=0;
                break;
            }
            k++;
        }
        if(flag){
            cout<<i<<endl;
        }
    }
}

int main()
{
   char *txt = "AABAACAADAABAAABAA";
   char *pat = "AABA";
   cout<<"Naive Searching"<<endl;
   NaiveSearch(pat, txt);
   cout<<"Naive Searching"<<endl;
   NaiveSearch(pat, txt);
   return 0;
}
