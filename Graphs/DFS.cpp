#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include "Graph.cpp"

void Graph::DFSUntil(int s,int visited[]){
    visited[s] = true;
    cout<<s<<" ";
    list<int>::iterator it;
    for(it=adj[s].begin();it!=adj[s].end();it++){
        if(visited[*it]==0){
            cout<<*it<<endl;
            DFSUntil(*it,visited);
        }
    }
}

void Graph::DFS(int s){
    int visited[V];
    for(int i=0;i<V;i++){
        visited[i] = 0;
    }
    DFSUntil(s,visited);
}

int main(){
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    cout << "Following is Depth First Traversal (starting from vertex 2)";
    g.DFS(2);
    return 0;
}
