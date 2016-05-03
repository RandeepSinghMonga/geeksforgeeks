#include <iostream>
using namespace std;
#include <bits/stdc++.h>

struct Graph{
	vector<pair<int,pair<int,int>>> edges;
	int v;
	Graph(int v){
		this->v = v;
	}
	int unionFind();
	void KruskalMST();
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
    for(int i = 0; i < g->edges.size(); ++i){
        int x = Find(parent, g->edges[i].second.first);
        int y = Find(parent, g->edges[i].second.second);
        if (x == y)
            return 1;
        Union(parent, x, y);
    }
    return 0;
}

void Graph::KruskalMST(){
	Graph *g = this;
	sort(g->edges.begin(),g->edges.end());
	Graph *ans = new Graph(g->v);
	for(int i=0;i<g->edges.size();i++){
		ans->edges.push_back(g->edges[i]);
		if(ans->unionFind()){
			ans->edges.pop_back();
		}
	}
	sort(ans->edges.begin(),ans->edges.end());
	for(int i=0;i<ans->edges.size();i++){
		cout<<ans->edges[i].second.first<<" "<<ans->edges[i].second.second<<endl;
	}
}

int main(){
	Graph *g = new Graph(9);
	g->edges.push_back(make_pair(4,make_pair(0,1)));
	g->edges.push_back(make_pair(8,make_pair(0,7)));
	g->edges.push_back(make_pair(8,make_pair(1,2)));
	g->edges.push_back(make_pair(11,make_pair(1,7)));
	g->edges.push_back(make_pair(7,make_pair(2,3)));
	g->edges.push_back(make_pair(2,make_pair(2,8)));
	g->edges.push_back(make_pair(4,make_pair(2,5)));
	g->edges.push_back(make_pair(9,make_pair(3,4)));
	g->edges.push_back(make_pair(14,make_pair(3,5)));
	g->edges.push_back(make_pair(10,make_pair(4,5)));
	g->edges.push_back(make_pair(2,make_pair(5,6)));
	g->edges.push_back(make_pair(1,make_pair(6,7)));
	g->edges.push_back(make_pair(6,make_pair(6,8)));
	g->edges.push_back(make_pair(7,make_pair(7,8)));
    g->KruskalMST();
    return 0;
}
