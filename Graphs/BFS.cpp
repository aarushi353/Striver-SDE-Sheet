#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
     vector<int> bfsOfGraph(int V, vector<int> adj[]){
        vector<int> bfs;
        vector<bool> visited(V, false);
        queue<int> q;
        visited[0]=true;
        q.push(0);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            for(auto it:adj[node]){
                if(visited[it]==false){
                  q.push(it);
                  visited[it]=true;
                }
            }
        }
        return bfs;
     }
};

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
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

// Time Complexity : O(N+E)
// Space Complexity : O(N+E) + O(N) + O(N)

