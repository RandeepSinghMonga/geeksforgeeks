#include <iostream>
#include <cstring>
using namespace std;

int max(int a,int b){
    return a>b?a:b;
}

int lpsR(char *str,int i,int j){
    if(i==j){
        return 1;
    }
    if((i+1)==j && str[i]==str[j]){
        return 2;
    }
    else if(str[i]==str[j]){
        return lpsR(str,i+1,j-1)+2;
    }
    else{
        return max(lpsR(str,i+1,j),lpsR(str,i,j-1));
    }
}

int lpsDP(char *str){
    int n = strlen(str);
    int arr[n][n];
    for(int x=0;x<n;x++){
        for(int i=0;i<n-x;i++){
            int j = x+i;
            if(i==j){
                arr[i][j]=1;
            }
            else if(i+1==j && str[i]==str[j]){
                arr[i][j]=2;
            }
            else if(str[i]==str[j]){
                arr[i][j] = arr[i+1][j-1] + 2;
            }
            else{
                arr[i][j] = max(arr[i+1][j],arr[i][j-1]);
            }
        }
    }
    return arr[0][n-1];
}

int main()
{
    char seq[] = "GEEKSFORGEEKS";
    int n = strlen(seq);
    cout<<"The length of the LPS is "<<lpsR(seq,0,n-1)<<endl;
    cout<<"The length of the LPS is "<<lpsDP(seq);
    return 0;
}
