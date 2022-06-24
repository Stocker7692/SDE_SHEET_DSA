#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0;
        int ma=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1) ans++;
            else{
                
                ma=max(ma,ans);
                ans=0;
            }
        }
        ma=max(ma,ans);
        return ma;
        
    }
};