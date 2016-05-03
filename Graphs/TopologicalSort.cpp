#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include "Graph.cpp"

int Graph::topologicalSortUtil(int s,int visited[],stack<int>* stk){
    visited[s]=1;
    list<int>::iterator it;
    for(it=adj[s].begin();it!=adj[s].end();it++){
        if(!visited[*it]){
            topologicalSortUtil(*it,visited,stk);
        }
    }
    (*stk).push(s);
}

void Graph::topologicalSort(){
    stack <int> stk;
    int visited[V];
    for(int i=0;i<V;i++){
        visited[i]=0;
    }
    for(int i=0;i<V;i++){
        if(visited[i]==0){
            topologicalSortUtil(i,visited,&stk);
        }
    }
    cout<<stk.size()<<endl;
    while(!stk.empty()){
        cout<<stk.top()<<" ";
        stk.pop();
    }
}

int main()
{
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    cout << "Following is a Topological Sort of the given graph \n";
    g.topologicalSort();

    return 0;
}
