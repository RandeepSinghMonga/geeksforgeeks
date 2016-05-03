#include <iostream>
using namespace std;
#include <bits/stdc++.h>

void BellmanFord(vector<vector<pair<int,int>> graph,int src){
	int v = graph->edges.size();
	vector<int> ans(v,INT_MAX);
	ans[src] = 0;
	for(int i=0;i<v-1;i++){
		for(int i=0;i<graph.size();i++){
			if(ans[i]==INT_MAX)continue;
			for(int j=0;j<graph[i].size();j++){
				if(ans[graph[i][j].first] > ans[i] + graph[i][j].second){
					ans[graph[i][j].first] > ans[i] + graph[i][j].second;
				}
			}
		}
	}
	return ans;
}

int main() {
	vector<vector<pair<int,int>>> graph;

	return 0;
}
