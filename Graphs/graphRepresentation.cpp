#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin>>n>>m;

  //declare the adjacent matrix
  int adj[n+1][n+1];

  //take edges as input
  for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    adj[u][v]=1;
    adj[v][u]=1;
  }
  for(int i=0;i<m;i++){
    for(int j=0;j<m;j++){
      cout<<adj[i][j];
    }
    cout<<endl;
  }
  return 0;
  
}