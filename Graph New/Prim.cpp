#include <iostream>
using namespace std;
#include <bits/stdc++.h>
#define pp pair<int,int>
#define first f
#define second s
#define make_pair mp

struct Graph{
	vector<vector<pp>> edges;
	int v;
	Graph(int v){
		this->v = v;
		this->edges.resize(v);
	}
	void PrimMST();
};


void Graph::PrimMST(){
	Graph *g = new Graph();
	vector<pp> ans;
	priority_queue<pair<int,pp>> pq;
	vector<int> visited(g->v,0);
	vector<pp> temp = g->edges[0];
	visited[0]=1;
	for(int i=0;i<temp.size();i++){
		pq.insert(mp(temp[i].f,mp(0,temp[i].s)));
	}
	int count = 1;
	while(count < g->v){
		pair<int,pp> node = pq.top();
		pq.pop();
		if(visited[node.s.s]==0){
			ans.push_back(node.s.f,node.s.s);
			visited[node.s.s] = 1;
			count++;
			temp = g->edges[node.s.s];
			for(int i=0;i<temp.size();i++){
				if(temp[i].s != node.s.f){
					pq.insert();
				}
			}
		}
	}
	//print ans
}

int main(){
	Graph *g = new Graph(9);
	g->edges[0].push_back(make_pair(4,1)));
	g->edges[1].push_back(make_pair(4,0)));
	g->edges[0].push_back(make_pair(8,7)));
	g->edges[7].push_back(make_pair(8,0)));
	g->edges[1].push_back(make_pair(8,2)));
	g->edges[2].push_back(make_pair(8,1)));
	g->edges[1].push_back(make_pair(11,7)));
	g->edges[7].push_back(make_pair(11,1)));
	g->edges[2].push_back(make_pair(7,3)));
	g->edges[3].push_back(make_pair(7,2)));
	g->edges[2].push_back(make_pair(2,8)));
	g->edges[8].push_back(make_pair(2,2)));
	g->edges[2].push_back(make_pair(4,5)));
	g->edges[5].push_back(make_pair(4,2)));
	g->edges[3].push_back(make_pair(9,4)));
	g->edges[4].push_back(make_pair(9,3)));
	g->edges[3].push_back(make_pair(14,5)));
	g->edges[5].push_back(make_pair(14,3)));
	g->edges[4].push_back(make_pair(10,5)));
	g->edges[5].push_back(make_pair(10,4)));
	g->edges[5].push_back(make_pair(2,6)));
	g->edges[6].push_back(make_pair(2,5)));
	g->edges[6].push_back(make_pair(1,7)));
	g->edges[7].push_back(make_pair(1,6)));
	g->edges[6].push_back(make_pair(6,8)));
	g->edges[8].push_back(make_pair(6,6)));
	g->edges[7].push_back(make_pair(7,8)));
	g->edges[8].push_back(make_pair(7,7)));
    g->PrimsMST();
    return 0;
}
