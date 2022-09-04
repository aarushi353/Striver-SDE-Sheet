// Rules
// 1. Sort all nodes in order of finishing time - Topo Sort -> O(n)
// 2. Transpose the graph ( all directions of edges get reversed ) -> O(N+E)
// 3. DFS according to the finishing time -> O(N+E)
// TC -> O(N+E)
// SC -> O(N+E) [For storing the transpose graph] + O(N) [For storing the visited array] + O(N) [For stack required for the topological sort]

#include<bits/stdc++.h>
using namespace std;

void dfs(int node, stack<int> &st, vector<int> &vis, vector<int> adj[]){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it, st, vis, adj);
        }
    }
}

void revDfs(int node, vector<int> &vis, vector<int> transpose[]){
    cout<<node<<" ";
    vis[node] = 1;
    for(auto it:transpose[node]){
        if(!vis[it]){
            revDfs(it, vis, transpose);
        }
    }
}

int main(){
    int n=6, m=7;
    vector<int> adj[n+1];
    adj[1].push_back(3);
    adj[2].push_back(1);
    adj[3].push_back(2);
    adj[3].push_back(5);
    adj[4].push_back(6);
    adj[5].push_back(4);
    adj[6].push_back(5);

    // Topo sort
    stack<int> st;
    vector<int> vis(n+1, 0);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i, st, vis, adj);
        }
    }

    // Transpose the graph
    vector<int> transpose[n+1];

    for(int i=1;i<=n;i++){
        vis[i] = 0;
        for(auto it: adj[i]){
            transpose[it].push_back(i);
        }
    }

    // DFS acc to finishing time

    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(!vis[node]){
            cout<<"SCC: ";
            revDfs(node, vis, transpose);
            cout<<endl;
        }
    }
    return 0;
}


