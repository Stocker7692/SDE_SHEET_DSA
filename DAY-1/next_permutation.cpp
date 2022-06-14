#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int l,k;
        for(l=n-2;l>=0;l--){
            if(nums[l]<nums[l+1]) break;
        }
        if(l<0){
            reverse(nums.begin(),nums.end());
        }
        else{
            for(k=n-1;k>l;k--){
                if(nums[k]>nums[l]) break;
            }
            swap(nums[l],nums[k]);
            reverse(nums.begin()+l+1,nums.end());
        }
        
    }
};