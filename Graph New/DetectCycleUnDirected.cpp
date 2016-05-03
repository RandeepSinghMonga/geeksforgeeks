#include <iostream>
using namespace std;
#include <bits/stdc++.h>
#include <Graph.cpp>

int Graph::detectUDCycle(int src){
	Graph *g = this;
	vector<int> visited(g->adj.size(),0);
	stack<pair<int,int>> stk;
	stk.push(make_pair(src,-1));
	visited[src] = 1;
	while(!stk.empty()){
		int parent = stk.top().second;
		int curr = stk.top().first;stk.pop();
		for(int i=0;i<g->adj[curr].size();i++){
			if(!visited[g->adj[curr][i]]){
				stk.push(make_pair(g->adj[curr][i],curr));
				visited[g->adj[curr][i]] = 1;
			}
			else if(g->adj[curr][i] != parent){
				return 1;
			}
		}
	}
	return 0;
}

int main(){
    Graph g1(5);
    g1.AddUDEdge(1, 0);
    g1.AddUDEdge(0, 2);
    g1.AddUDEdge(2, 0);
    g1.AddUDEdge(0, 3);
    g1.AddUDEdge(3, 4);
    g1.detectUDCycle(0)? cout << "Graph contains cycle\n":
                   cout << "Graph doesn't contain cycle\n";

    Graph g2(3);
    g2.AddUDEdge(0, 1);
    g2.AddUDEdge(1, 2);
    g2.detectUDCycle(0)? cout << "Graph contains cycle\n":
                   cout << "Graph doesn't contain cycle\n";
    return 0;
}
