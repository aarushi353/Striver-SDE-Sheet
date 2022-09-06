#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lis(int n, int m, vector<int>&v1,vector<int>&v2,vector<vector<int>>&dp){
        if(n==0||m==0){
            return 0;
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        if(v1[n-1]==v2[m-1]){
            return dp[n][m] = 1+lis(n-1, m-1, v1, v2, dp);
        }
        else{
            return dp[n][m] = max(lis(n-1, m, v1, v2, dp), lis(n, m-1, v1, v2, dp));
        }
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> v1 = nums;
        set<int> st;
        //since strictly increasing is asked for so we can count length as 1 for consecutive equal elements
        //thus storing them in set is needed to find number of unique elements
        
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        vector<int> v2;
        for(auto it=st.begin();it!=st.end();it++){
            v2.push_back(*it);
        }
        
        int n=v1.size();
        int m=v2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        int ans  = lis(n,m,v1,v2,dp);
        return ans;
    }
};