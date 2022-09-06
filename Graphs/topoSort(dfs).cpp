#include<bits/stdc++.h>
using namespace std;

void findTopoSort(int node, vector<int> &vis, stack<int> &st, vector<int> adj[]){
    vis[node] = 1;
    for(auto it:adj[node]){
        if(!vis[it]){
            findTopoSort(it, vis, st, adj);
        }
    }
    st.push(node);
}

vector<int> topoSort(int N, vector<int> adj[]){
    stack<int> st;
    vector<int> vis(N, 0);
    for(int i=0;i<N;i++){
        if(vis[i] == 0){
            findTopoSort(i, vis, st, adj);
        }
    }
    vector<int> topo;
    while(!st.empty()){
        topo.push_back(st.top());
        st.pop();
    }
    return topo;
}

int main()
{

    	vector<int> adj[6];
    	adj[5].push_back(2);
    	adj[5].push_back(0);
    	adj[4].push_back(0);
    	adj[4].push_back(1);
    	adj[3].push_back(1);
    	adj[2].push_back(3);

 
    	vector<int> v=topoSort(6, adj);
    	for(auto it:v)
    	cout<<it<<" ";
    

    return 0;
}

// T.C. = O(N+E)
// S.C. = O(N)
