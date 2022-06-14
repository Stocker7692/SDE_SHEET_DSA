#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int ma=0,ans=INT_MIN;
        for(int i=0;i<nums.size();i++){
            ma+=nums[i];
            
            ans=max(ma,ans);
            if(ma<0){
                ma=0;
            }
            
        }
        return ans;
        
    }
};