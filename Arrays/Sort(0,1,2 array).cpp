// M1-> Merge Sort (T.C. = O(N*logN), S.C = 0(1))

// M2-> Count 0,1,2 and override TC = O(N)+O(N), SC = O(1)

// M3-> 3-pointer approach

// This prob, a variation of dutch national flag algo
#include <bits/stdc++.h>
using namespace std  ;

class Solution{
    public:
    void sortArr(vector<int>& nums){
         int lo=0;
         int hi=nums.size()-1;
         int mid=0;

         while(mid<=hi){
            switch(nums[mid]){

                // if the element is 0
                case 0:
                    swap(nums[lo++], nums[mid++]);
                    break;
                
                // if the element is 1
                case 1:
                    mid++;
                    break;
                
                // if the element is 2
                case 2:
                     swap(nums[mid], nums[hi--]);
                     break;
            }
         }
    }
};

int main() {

    vector<int>arr = {0,2,1,0,1,0,2};
    int n = 7;

    Solution obj ;
    cout << "Before Sorting Array: "<<endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "  ;
    }
    cout<<endl;
    obj.sortArr(arr);
    cout << "After Sorting Array: "<<endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "  ;
    }
    return 0 ;
}
