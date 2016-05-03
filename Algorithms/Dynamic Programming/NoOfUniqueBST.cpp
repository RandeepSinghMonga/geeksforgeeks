#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int numTrees(int n) {
	int count[n + 1];
	for(int i=0;i<n+1;i++){
        count[i]=0;
	}
	count[0] = 1;
	count[1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= i - 1; j++) {
			count[i] = count[i] + count[j] * count[i - j - 1];
		}
	}
	return count[n];
}

int main(){
    cout<<numTrees(4);
    return 0;
}
