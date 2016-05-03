#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
public:
    Graph(int V);
    void addEdge(int v, int w);
    void printGraph();
    void BFS(int i);
    void DFS(int i);
    void DFSUntil(int s,int visited[]);
    void topologicalSort();
    int topologicalSortUtil(int v, int visited[], stack<int> *Stack);
    int isCyclic();
    int isCyclicUntil(int s,int visited[],int recurStack[]);
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

