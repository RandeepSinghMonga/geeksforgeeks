#include <bits/stdc++>
#include <iostream>
using namespace std;

struct Edge{
    int src, dest;
};

struct Graph{
    int V, E;
    struct Edge* edge;
};

struct Graph* createGraph(int V, int E){
    Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new (struct Edge*) malloc( graph->E * sizeof( struct Edge ) );
    return graph;
}

int isCycle(Graph* graph){
    int parent][graph->v];
    memset(parent,-1,);
}

int main()
{
    /*
         0
        |  \
        |    \
        1-----2
    */
    struct Graph* graph = createGraph(3, 3);
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[1].src = 1;
    graph->edge[1].dest = 2;
    graph->edge[2].src = 0;
    graph->edge[2].dest = 2;

    if (isCycle(graph))
        printf( "Graph contains cycle" );
    else
        printf( "Graph doesn't contain cycle" );
    return 0;
}
