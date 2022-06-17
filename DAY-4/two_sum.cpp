#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>m;
        int a;
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i])!=m.end()) {
                return {i,m[nums[i]]};
            }
            else{
                m[target-nums[i]]=i;
            }
        }
        
        return {};
        
    }
};