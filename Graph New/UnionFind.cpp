#include <iostream>
using namespace std;
#include <bits/stdc++.h>

struct Graph{
	vector<pair<int,int>> edges;
	int v;
	Graph(int v){
		this->v = v;
	}
	int unionFind();
};

int Find(vector<int> &parent,int i){
	if (parent[i] == -1)
        return i;
    return Find(parent, parent[i]);
}

void Union(vector<int> &parent,int x,int y){
	int xset = Find(parent, x);
    int yset = Find(parent, y);
    parent[xset] = yset;
}

int Graph::unionFind(){
	Graph *g = this;
	vector<int> parent(g->v,-1);
	//int *parent = (int*) malloc( g->v * sizeof(int) );
    //memset(parent, -1, sizeof(int) * g->v);
    for(int i = 0; i < g->edges.size(); ++i){
        int x = Find(parent, g->edges[i].first);
        int y = Find(parent, g->edges[i].second);
        if (x == y)
            return 1;
        Union(parent, x, y);
    }
    return 0;
}

int main(){
	Graph *g = new Graph(3);
	g->edges.push_back(make_pair(0,1));
    g->edges.push_back(make_pair(1,2));
    g->unionFind()? cout << "Graph contains cycle\n":
                   cout << "Graph doesn't contain cycle\n";
    g->edges.push_back(make_pair(0,2));
    g->unionFind()? cout << "Graph contains cycle\n":
                   cout << "Graph doesn't contain cycle\n";
    return 0;
}
