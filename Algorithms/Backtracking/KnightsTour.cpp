#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

int backtrack(int arr[100][100],int i,int j,int count,int n){
    if(count == n*n-1){
        return 1;
    }
    if(i+1<n && j+2<n && arr[i+1][j+2]==0){
        arr[i+1][j+2] = count;
        if(backtrack(arr,i+1,j+2,count+1,n)){
            return 1;
        }
        arr[i+1][j+2] = 0;
    }
    if(i-1>=0 && j+2<n && arr[i-1][j+2]==0){
        arr[i-1][j+2] = count;
        if(backtrack(arr,i-1,j+2,count+1,n)){
            return 1;
        }
        arr[i-1][j+2] = 0;
    }
    if(i+1<n && j-2>=0 && arr[i+1][j-2]==0){
        arr[i+1][j-2] = count;
        if(backtrack(arr,i+1,j-2,count+1,n)){
            return 1;
        }
        arr[i+1][j-2] = 0;
    }
    if(i-1>=0 && j-2>=0 && arr[i-1][j-2]==0){
        arr[i-1][j-2] = count;
        if(backtrack(arr,i-1,j-2,count+1,n)){
            return 1;
        }
        arr[i-1][j-2] = 0;
    }
    if(i+2<n && j+1<n && arr[i+2][j+1]==0){
        arr[i+2][j+1] = count;
        if(backtrack(arr,i+2,j+1,count+1,n)){
            return 1;
        }
        arr[i+2][j+1] = 0;
    }
    if(i-2>=0 && j+1<n && arr[i-2][j+1]==0){
        arr[i-2][j+1] = count;
        if(backtrack(arr,i-2,j+1,count+1,n)){
            return 1;
        }
        arr[i-2][j+1] = 0;
    }
    if(i+2<n && j-1>=0 && arr[i+2][j-1]==0){
        arr[i+2][j-1] = count;
        if(backtrack(arr,i+2,j-1,count+1,n)){
            return 1;
        }
        arr[i+2][j-1] = 0;
    }
    if(i-2>=0 && j-1>=0 && arr[i-2][j-1]==0){
        arr[i-2][j-1] = count;
        if(backtrack(arr,i-2,j-1,count+1,n)){
            return 1;
        }
        arr[i-2][j-1] = 0;
    }
    return 0;
}

void KnightsTour(int n){
	int arr[100][100];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			arr[i][j]=0;
		}
	}
	arr[0][0]=1;
	backtrack(arr,0,0,0,n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<arr[i][j]<<"   ";
		}
		cout<<endl;
	}
}

int main() {
	KnightsTour(5);
	return 0;
}
