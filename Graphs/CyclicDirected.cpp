#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include "Graph.cpp"

int Graph::isCyclicUntil(int s,int visited[],int recurStack[]){
    visited[s]=1;
    recurStack[s]=1;
    list<int>::iterator it;
    for(it=adj[s].begin();it!=adj[s].end();it++){
        if((visited[*it]==0 && isCyclicUntil(*it,visited,recurStack)) || recurStack[*it])
            return 1;
    }
    recurStack[s] = 0;
    return 0;
}

int Graph::isCyclic(){
    int visited[V],recurStack[V];
    for(int i=0;i<V;i++){
        visited[i]=0;
        recurStack[i]=0;
    }
    for(int i=0;i<V;i++){
        if(visited[i]==0){
            if(isCyclicUntil(i,visited,recurStack))
                return 1;
        }
    }
    return 0;
}

int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    if(g.isCyclic())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
    return 0;
}
