#include <iostream>
using namespace std;
#include <bits/stdc++.h>

struct Graph{
	vector<vector<int>> adj;
	Graph(int v){
		adj.resize(v);
	}
	void AddEdge(int src,int dest){
		adj[src].push_back(dest);
	}
	void AddUDEdge(int src,int dest){
		adj[src].push_back(dest);
		adj[dest].push_back(src);
	}
	void printGraph(){
		Graph *g = this;
        for(int i=0;i<g->adj.size();i++){
        	cout<<i<<": ";
        	for(int j=0;j<g->adj[i].size();j++){
        		cout<<g->adj[i][j];
        	}
        	cout<<endl;
        }
	}
	vector<int> Dfs(int src);
	vector<int> Bfs(int src);
	int detectCycle(int src);
	int detectUDCycle(int src);
};

struct undirectedGraph{

};
