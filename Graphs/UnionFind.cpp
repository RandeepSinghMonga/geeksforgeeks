#include <iostream>
using namespace std;
#include <bits/stdc++.h>

struct Edge{
    int src,dest;
};

struct Graph{
    int v,e;
    Edge* edge;
};

Graph* createGraph(int v,int e){
    Graph* graph = new Graph;
    graph->v = v;
    graph->e = e;
    graph->edge = new Edge[graph->e];
}

int find(int parent[],int i){
    if(parent[i]==-1){
        return i;
    }
    return find(parent,parent[i]);
}

void Union(int parent[],int x,int y){
    int xset = find(parent,x);
    int yset = find(parent,y);
    parent[xset] =  yset;
}

int isCycle(Graph *graph){
    int *parent = new int[graph->v];
    memset(parent,-1,sizeof(int)*graph->v);
    for(int i=0;i<graph->e;i++){
        int x = find(parent,graph->edge[i].src);
        int y = find(parent,graph->edge[i].dest);
        if(x==y){
            return 1;
        }
        Union(parent,x,y);
    }
    return 0;
}

int main(){
    /*
         0
        |  \
        |    \
        1-----2 */
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
