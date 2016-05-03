#include <iostream>
using namespace std;
#include <bits/stdc++.h>
#define V 4


int isBipartite(int G[][V],int src){
    int color[V];
    queue <int> q;
    for(int i=0;i<V;i++){
        color[i]=-1;
    }
    color[src]=1;
    q.push(src);
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        for(int i=0;i<V;i++){
            if(G[temp][i] && color[i]== -1){
                color[i] = 1-color[temp];
                q.push(i);
            }
            else if(G[temp][i] && color[i]==color[temp]){
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    int G[][V] ={{0, 1, 0, 1},
                {1, 0, 1, 0},
                {0, 1, 0, 1},
                {1, 0, 1, 0}
    };

    isBipartite(G, 0) ? cout << "Yes" : cout << "No";
    return 0;
}
