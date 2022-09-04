// Brute force
// Key : This array holds the weight/ cost of the MST(intialized to INT_MAX except the index 0 which is set with value of zero)
// MST : This is a boolean array which indicates whether a node is already a part of MST or not(initialized to false except the index 0 which is true)
// Parent :  This indicates the parent of a particular node in the MST(initialized to -1)

#include<bits/stdc++.h>
using namespace std;

int main(){
	int N=5,m=6;
	vector<pair<int,int> > adj[N]; 


	adj[0].push_back({1,2});
	adj[0].push_back({3,6});
	adj[1].push_back({0,2});
	adj[1].push_back({2,3});
	adj[1].push_back({3,8});
	adj[1].push_back({4,5});
	adj[2].push_back({1,3});
	adj[2].push_back({4,7});
	adj[3].push_back({0,6});
	adj[3].push_back({1,8});
	adj[4].push_back({1,5});
	adj[4].push_back({2,7});
	
    int parent[N];
    int key[N]; 
    bool mstSet[N]; 
  
    for (int i = 0; i < N; i++) 
        key[i] = INT_MAX, mstSet[i] = false; 
    key[0] = 0; 
    parent[0] = -1; 
    int ansWeight = 0;
    for (int count = 0; count < N - 1; count++)
    { 
        
        int mini = INT_MAX, u; 
  
        for (int v = 0; v < N; v++) 
{
            if (mstSet[v] == false && key[v] < mini) 
                mini = key[v], u = v; 
}
                 mstSet[u] = true; 
        
        for (auto it : adj[u]) {
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v]) 
                parent[v] = u, key[v] = weight; 
        }
            
    } 
    
    
    for (int i = 1; i < N; i++) 
        cout << parent[i] << " - " << i <<" \n"; 
	return 0;
}

// Time Complexity: O(N^2). Going through N Node for N-1 times
// Space Complexity: O(N). 3 arrays of size N

// Optimized Approach
#include<bits/stdc++.h>
using namespace std;

int main(){
	int N=5,m=6;
	vector<pair<int,int> > adj[N]; 
	adj[0].push_back({1,2});
	adj[0].push_back({3,6});
	adj[1].push_back({0,2});
	adj[1].push_back({2,3});
	adj[1].push_back({3,8});
	adj[1].push_back({4,5});
	adj[2].push_back({1,3});
	adj[2].push_back({4,7});
	adj[3].push_back({0,6});
	adj[3].push_back({1,8});
	adj[4].push_back({1,5});
	adj[4].push_back({2,7});



	
	
    int parent[N]; 
      
    int key[N]; 
      
    bool mstSet[N]; 
  
    for (int i = 0; i < N; i++) 
        key[i] = INT_MAX, mstSet[i] = false; 
    
    priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;

    key[0] = 0; 
    parent[0] = -1; 
    pq.push({0, 0});

    while(!pq.empty())
    { 
        int u = pq.top().second; 
        pq.pop(); 
        
        mstSet[u] = true; 
        
        for (auto it : adj[u]) {
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v]) {
                parent[v] = u;
	    key[v] = weight; 
                pq.push({key[v], v});    
            }
        }
            
    } 
    
    for (int i = 1; i < N; i++) 
        cout << parent[i] << " - " << i <<" \n"; 
	return 0;
}

// Time Complexity: O(NlogN). N iterations and logN for priority queue
// Space Complexity: O(N). Three arrays and priority queue
