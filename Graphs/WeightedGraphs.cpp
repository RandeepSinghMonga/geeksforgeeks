#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class AdjListNode
{
    int v;
    int weight;
public:
    AdjListNode(int _v, int _w)  { v = _v;  weight = _w;}
    int getV()       {  return v;  }
    int getWeight()  {  return weight; }
};

class Graph
{
    int V;
    list<AdjListNode> *adj;
    void topologicalSortUtil(int v, int visited[], stack<int> *Stack);
public:
    Graph(int V);
    void addEdge(int u, int v, int weight);
    void longestPath(int s);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<AdjListNode>[V];
}

void Graph::addEdge(int u, int v, int weight)
{
    AdjListNode node(v, weight);
    adj[u].push_back(node);
}
