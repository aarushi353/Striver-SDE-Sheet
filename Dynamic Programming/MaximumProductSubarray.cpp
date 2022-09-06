// Brute force
#include<bits/stdc++.h>
using namespace std;

int maxProductSubArray(vector<int>& nums){
    int result=INT_MIN;
    for(int i=0;i<nums.size()-1;i++){
        for(int j=i+1;j<nums.size();j++){
            int prod = 1;
            for(int k=i;k<=j;k++){
                prod*=nums[k];
            }
            result = max(result, prod);
        }
    }
    return result;
}

int main(){
    vector<int> nums = {1,2,-3,0,-4,-5};
    cout<<"The maximum product subarray: "<<maxProductSubArray(nums);
    return 0;
}

// T.C. = O(n^3)
// S.C. = O(1)

// Optimized brute force

#include<bits/stdc++.h>
using namespace std;

int maxProductSubArray(vector<int>& nums){
    int result = nums[0];
    for(int i=0;i<nums.size()-1;i++){
        int p = nums[i];
        for(int j=i+1;j<nums.size();j++){
            result = max(result, p);
            p*=nums[j];
        }
        result = max(result, p); // manages (n-1)th term
    }
    return result;
}

int main(){
    vector<int> nums = {1,2,-3,0,-4,-5};
    cout<<"The maximum product subarray: "<<maxProductSubArray(nums);
    return 0;
}

// T.C. = O(n^2)
// S.C. = O(1)

// Kadane's Algo

// Initially store 0th index value in prod1, prod2 and result.
// Traverse the array from 1st index. 
// For each element, update prod1 and prod2.
// Prod1 is maximum of current element, product of current element and prod1, product of current element and prod2
// Prod2 is minimum of current element, product of current element and prod1, product of current element and prod2
// Return maximum of result and prod1

#include<bits/stdc++.h>
using namespace std;

int maxProductSubArray(vector<int>& nums){
    int prod1 = nums[0], prod2 = nums[0], result = nums[0];
    for(int i=1;i<nums.size();i++){
        int temp = max({nums[i], prod1*nums[i], prod2*nums[i]});
        prod2 = min({nums[i], prod1*nums[i], prod2*nums[i]});
        prod1 = temp;

        result = max(result, prod1);
    }

    return result;
}

int main() {
    vector<int> nums = {1,2,-3,0,-4,-5};
    cout<<"The maximum product subarray: "<<maxProductSubArray(nums);
    return 0;
}

// T.C. = O(N)
// S.C. = O(1)