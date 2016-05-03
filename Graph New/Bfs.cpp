#include <iostream>
using namespace std;
#include <bits/stdc++.h>
#include <Graph.cpp>


vector<int> Graph::Bfs(int src){
	vector<int> ans;
	Graph *g = this;
	queue<int> q;
	vector<int> visited(g->adj.size(),0);
	q.push(src);
	visited[src] = 1;
	while(!q.empty()){
		int curr = q.front();q.pop();
		ans.push_back(curr);
		for(int i=0;i<g->adj[curr].size();i++){
			if(!visited[g->adj[curr][i]]){
				q.push(g->adj[curr][i]);
				visited[g->adj[curr][i]] = 1;
			}
		}
	}
	return ans;
}

int main(){
    Graph *g = new Graph(4);
    g->AddEdge(0, 1);
    g->AddEdge(0, 2);
    g->AddEdge(1, 2);
    g->AddEdge(2, 0);
    g->AddEdge(2, 3);
    g->AddEdge(3, 3);
    cout << "Following is Depth First Traversal (starting from vertex 2) \n";
    vector<int> ans = g->Bfs(2);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
