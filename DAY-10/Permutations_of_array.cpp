#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    void solve(int ind,vector<int>&nums,vector<vector<int>>&res){
        if(ind==nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i=ind;i<nums.size();i++){
            swap(nums[ind],nums[i]);
            solve(ind+1,nums,res);
            swap(nums[ind],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        solve(0,nums,res);
        return res;
        
    }
};