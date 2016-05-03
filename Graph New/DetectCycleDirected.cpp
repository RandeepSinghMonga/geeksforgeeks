#include <iostream>
using namespace std;
#include <bits/stdc++.h>
#include <Graph.cpp>

int Graph::detectCycle(int src){
	Graph *g = this;
	vector<int> visited(g->adj.size(),0);
	vector<int> recur(g->adj.size(),0);
	stack<int> stk;
	stk.push(src);
	visited[src] = 1;
	recur[src] = 1;
	while(!stk.empty()){
		int curr = stk.top();stk.pop();
		cout<<curr<<" ";
		for(int i=0;i<g->adj[curr].size();i++){
			if(recur[g->adj[curr][i]]){
				return 1;
			}
			if(!visited[g->adj[curr][i]]){
				stk.push(g->adj[curr][i]);
				visited[g->adj[curr][i]] = 1;
				recur[g->adj[curr][i]] = 1;
			}
		}
		recur[curr] = 0;
	}
	return 0;
}
