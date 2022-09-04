// shortest distance with negative edge
// why not dijkstras?
// With the presence of negative edge weights, our algorithm would continue to update the distance array with lesser and lesser values and we might end up in time limit exceeded or segmentation fault error.

//Technique used here is "Realxing edges"
// N-1 Iterations because we have N edges, the maximum number of edges we could have between any two nodes is N-1 in a single path.

#include<bits/stdc++.h>
using namespace std;
struct node{
    int u;
    int v;
    int wt;
    node(int first, int second, int weight){
        u = first;
        v = second;
        wt = weight;
    }
};

int main(){
    int N=6, m=7;
    vector<node> edges;
    edges.push_back(node(0,1,5));
    edges.push_back(node(1,2,-2));
    edges.push_back(node(1,5,-3));
    edges.push_back(node(2,4,3));
    edges.push_back(node(3,2,6));
    edges.push_back(node(3,4,-2));
    edges.push_back(node(5,3,1));
    int src=0;
    int inf = 10000000;
    vector<int> dist(N, inf);
    dist[src] = 0;
    for(int i=1;i<=N-1;i++){
        for(auto it:edges){
            if(dist[it.u] + it.wt < dist[it.v]){
                dist[it.v] = dist[it.u] + it.wt;
            }
        }
    }

    int f1=0;
    for(auto it:edges){
        if(dist[it.u]+it.wt<dist[it.v]){
            cout<<"Negative cycle";
            f1=1;
            break;
        }
    }

    if(!f1){
        for(int i=0;i<N;i++){
            cout<<dist[i]<<" ";
        }
    }
}
