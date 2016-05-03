
#include <iostream>
#include <cstdlib>
using namespace std;
#define N 4

int backtrack(int arr[N][N],int x,int y,int sol[N][N]){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<sol[i][j];
		}
		cout<<endl;
	}
	cout<<endl;
	if(x==N-1 && y==N-1){
		return 1;
	}
	if(x+1<N && y<N && x+1>=0 && y>=0 && arr[x+1][y]==1 && sol[x+1][y]==0){
		sol[x+1][y] = 1;
		if(backtrack(arr,x+1,y,sol))
			return 1;
		else
			sol[x+1][y] = 0;
	}
	if(x-1<N && y<N && x-1>=0 && y>=0 && arr[x-1][y]==1 && sol[x-1][y]==0){
		sol[x-1][y] = 1;
		if(backtrack(arr,x-1,y,sol))
			return 1;
		else
			sol[x-1][y] = 0;
	}
	if(x<N && y-1<N && x>=0 && y-1>=0 && arr[x][y-1]==1 && sol[x][y-1]==0){
		sol[x][y-1] = 1;
		if(backtrack(arr,x,y-1,sol))
			return 1;
		else
			sol[x][y-1] = 0;
	}
	if(x<N && y+1<N && x>=0 && y+1>=0 && arr[x][y+1]==1 && sol[x][y+1]==0){
		sol[x][y+1] = 1;
		if(backtrack(arr,x,y+1,sol))
			return 1;
		else
			sol[x][y+1] = 0;
	}
	return 0;
}

void solveMaze(int maze[N][N]){
	int sol[N][N]={
		{0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
	};
	sol[0][0]=1;
	backtrack(maze,0,0,sol);
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<sol[i][j];
		}
		cout<<endl;
	}
}

int main(){
    int maze[N][N]  =  {
		{1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };
    solveMaze(maze);
    return 0;
}
