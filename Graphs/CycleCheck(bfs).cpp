#include<bits/stdc++.h>
using namespace std;

bool checkForCycle(int s, int V, vector<int> adj[], vector<int>& visited){
    queue<pair<int, int>> q;
    visited[s]=true;
    q.push({s, -1});

    while(!q.empty()){
        int node = q.front().first;
        int par = q.front().second;
        q.pop();

        for(auto it:adj[node]){
            if(!visited[it]){
                visited[it]=true;
                q.push({it, node});
            } else if(par!=it){
                return true;
            }
        }
        return false;
    }
}


bool isCycle(int V, vector<int> adj[]){
    vector<int> vis(V+1, 0);
    for(int i=1;i<=V;V++){
        if(!vis[i]){
            if(checkForCycle(i, V, adj, vis)) return true;
        }
    }
    return false;
}

int main(){
    int tc;
    cin>>tc;
    while(tc--){
        int V, E;
        vector<int> adj[V];
        for(int i=0;i<E;i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if(isCycle(V, adj)){
            cout<<"Cycle is present"<<endl;
        } else{
            cout<<"Cycle is absent"<<endl;
        }
     }
    return 0;
}

// Time Complexity: O(N+E),  N is the time taken and E is for traveling through adjacent nodes overall. 
// Space Complexity: O(N+E) +  O(N) + O(N) , space for adjacent list , array and queue

