#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include "Graph.cpp"

void Graph::printGraph(){
    for(int i=0;i<V;i++){
        cout<<i<<": head->";
        list<int>::iterator it;
        for(it=adj[i].begin();it!=adj[i].end();it++){
            cout<<*it<<"->";
        }
        cout<<"NULL"<<endl;
    }
}

int main(){
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.printGraph();
    return 0;
}
