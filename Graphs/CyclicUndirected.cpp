#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class Graph
{
    int V;
    list<int> *adj;
    int isCyclicUtil(int v, int visited[], int parent);
public:
    Graph(int V);
    void addEdge(int v, int w);
    int isCyclic();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
    adj[w].push_back(v);
}

int Graph::isCyclicUtil(int s,int visited[],int parent){
    visited[s]=1;
    list<int>::iterator it;
    for(it=adj[s].begin();it!=adj[s].end();it++){
        if(!visited[*it]){
            if(isCyclicUtil(*it,visited,s)){
                return 1;
            }
        }
        else if(*it != parent){
            return 1;
        }
    }
    return 0;
}

int Graph::isCyclic(){
    int visited[V];
    for(int i=0;i<V;i++){
        visited[i]=0;
    }
    for(int i=0;i<V;i++){
        if(visited[i]==0){
            if(isCyclicUtil(i,visited,-1))
                return 1;
        }
    }
    return 0;
}

int main()
{
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 0);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.isCyclic()? cout << "Graph contains cycle\n":
                   cout << "Graph doesn't contain cycle\n";

    Graph g2(3);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.isCyclic()? cout << "Graph contains cycle\n":
                   cout << "Graph doesn't contain cycle\n";

    return 0;
}
