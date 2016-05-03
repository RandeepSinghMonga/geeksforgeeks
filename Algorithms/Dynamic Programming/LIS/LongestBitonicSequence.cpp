#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int lbsDP(int arr[],int n){
    int lis[n],lds[n],lbs[n];

    for(int i=0;i<n;i++){
        lis[i]=1;
        lds[i]=1;
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j] && lis[j]>=lis[i]){
                lis[i]=lis[j]+1;
            }
        }
    }

    for(int i=n-2;i>=0;i--){
        for(int j=n-1;j>i;j--){
            if(arr[i]>arr[j] && lds[j]>=lds[i]){
                lds[i]=lds[j]+1;
            }
        }
    }

    lbs[0]=lis[0]+lds[0]-1;
    int max = lbs[0];
    for(int i=1;i<n;i++){
        lbs[i]=lis[i]+lds[i]-1;
        if(lbs[i]>max){
            max = lbs[i];
        }
    }

    return max;
}

int main()
{
    int arr[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Length of LBS is "<<lbsDP( arr, n )<<endl;
    return 0;
}
