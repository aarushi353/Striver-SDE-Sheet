#include <bits/stdc++.h>
using namespace std;

bool bipartiteDfs(int node, vector<int> adj[], int colour[]){
    if(colour[node]==-1){
        colour[node]=1;
    }
    for(auto it:adj[node]){
        if(colour[it]==-1){
            colour[it] = 1-colour[node];
            if(!bipartiteDfs(it, adj, colour)){
                return false;
            } else if(colour[it] == colour[node]){
                return false;
            }
        }
    }
    return true;
}

bool checkBipartite(vector<int> adj[], int n){
    int colour[n];
    memset(colour, -1, sizeof colour);
    for(int i=0;i<n;i++){
       if(colour[i] == -1){
        if(!bipartiteDfs(i, adj, colour)){
            return false;
        }
       }
    }
    return true;
}

void addedge(vector<int> adj[],int u,int v)
{
        adj[u].push_back(v); 
        adj[v].push_back(u);
}
int main() {
    
    vector<int> adj[6];
    addedge(adj,0,1);
    addedge(adj,1,2);
    addedge(adj,1,4);
    addedge(adj,1,5);
    addedge(adj,2,3);
    addedge(adj,3,4);
    addedge(adj,3,5);

    if(checkBipartite(adj, 6)) {
        cout << "It is a Bipartite Graph"; 
    } else {
        cout << "It is not a Bipartite Graph"; 
    }
    return 0;
}

// Time Complexity: O(V + E), since in its whole, it is a DFS implementation, V – vertices; E – edges;
// Space Complexity: O(V), because, apart from the graph, we maintain a color array.

