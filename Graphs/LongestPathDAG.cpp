#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include "WeightedGraphs.cpp"

void Graph::topologicalSortUtil(int v, int visited[], stack<int> *stk){
    visited[v]=1;
    list<AdjListNode>::iterator it;
    for(it=adj[v].begin();it!=adj[v].end();it++){
        if(!visited[it->getV()]){
            topologicalSortUtil(it->getV(),visited,stk);
        }
    }
    (*stk).push(v);
}

void Graph::longestPath(int s){
    int visited[V];
    for(int i=0;i<V;i++){
        visited[i]=0;
    }
    stack <int > stk;
    for(int i=0;i<V;i++){
        if(!visited[i]){
            topologicalSortUtil(i,visited,&stk);
        }
    }
    int dist[V];
    for(int i=0;i<V;i++){
        dist[i]=INT_MIN;
    }
    dist[s]=0;
    while(!stk.empty()){
        int temp = stk.top();
        stk.pop();
        if(dist[temp]!=INT_MIN){
            list <AdjListNode>::iterator it;
            for(it=adj[temp].begin();it!=adj[temp].end();it++){
                if(dist[it->getV()] < dist[temp] + it->getWeight()){
                    dist[it->getV()] = dist[temp] + it->getWeight();
                }
            }
        }
    }
    for(int i=0;i<V;i++){
        dist[i] == INT_MIN ? cout<<"INT_MIN " : cout<<dist[i]<<" ";
    }
}

int main(){
    Graph g(6);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 5, 1);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);
    int s = 1;
    cout << "Following are longest distances from source vertex " << s <<" \n";
    g.longestPath(s);
    return 0;
}
