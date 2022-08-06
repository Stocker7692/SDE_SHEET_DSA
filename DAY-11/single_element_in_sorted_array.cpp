#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int l=0,h=nums.size()-2;
        while(l<=h){
            int mid = (l+h)/2;
            if(nums[mid]==nums[mid^1]){
                l=mid+1;
            }
            else h=mid-1;
        }
        return nums[l];
        
        
    }
};