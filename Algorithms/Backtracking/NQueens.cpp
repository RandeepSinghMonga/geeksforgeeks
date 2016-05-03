#include <iostream>
using namespace std;

int isSafe(int arr[][100],int i,int j,int n){
	for(int k=0;k<n;k++){
		if(arr[k][j]==1){
			if(k==i)continue;
			return 0;
		}
		if(arr[i][k]==1){
			if(k==j)continue;	
			return 0;
		}
	}
	int k=1;
	while(i+k<n && j+k<n){
		if(arr[i+k][j+k]==1)return 0;
		k++;
	}
	k=1;
	while(i-k>=0 && j-k>=0){
		if(arr[i-k][j-k]==1)return 0;
		k++;
	}
	k=1;
	while(i+k<n && j-k>=0){
		if(arr[i+k][j-k]==1)return 0;
		k++;
	}
	k=1;
	while(i-k>=0 && j+k<n){
		if(arr[i-k][j+k]==1)return 0;
		k++;
	}
	return 1;
}

int backtrack(int arr[][100],int i,int n){
	if(i==n)return 1;
	for(int j=0;j<n;j++){
		if(isSafe(arr,i,j,n)){
			arr[i][j]=1;
			if(backtrack(arr,i+1,n)){
				return 1;
			}
			arr[i][j]=0;
		}
	}
	return 0;
}

void NQueens(int n){
	int arr[100][100];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			arr[i][j]=0;
		}
	}
	backtrack(arr,0,n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<arr[i][j];
		}
		cout<<endl;
	}
	cout<<endl;
}

int main(){
	NQueens(6);
	return 0;
}