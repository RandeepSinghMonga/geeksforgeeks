#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include "Graph.cpp"

void Graph::BFS(int s){
    int visited[V];
    for(int i=0;i<V;i++){
        visited[i] = 0;
    }
    queue <int> q;
    q.push(s);
    visited[s] = 1;
    while(!q.empty()){
        int temp = q.front();
        cout<<temp<<" ";
        q.pop();
        list<int>::iterator it;
        for(it=adj[temp].begin();it!=adj[temp].end();it++){
            if(visited[*it]==0){
                q.push(*it);
                visited[*it]=1;
            }
        }
    }
    cout<<endl;
}

int main(){
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    cout << "Following is Breadth First Traversal (starting from vertex 2)"<<endl;
    g.BFS(2);
    return 0;
}
