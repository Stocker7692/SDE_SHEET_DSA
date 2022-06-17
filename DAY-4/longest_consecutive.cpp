#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(int i:nums) st.insert(i);
        int res=0;
        for(int i=0;i<nums.size();i++) {
            if(st.count(nums[i]-1)==0) {
                int curr=1;
                while(st.count(nums[i]+curr)>0) curr++;
                res=max(res, curr);
            }
        }
        return res;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        sort(nums.begin(),nums.end());
        int ans=1;
        int res=1;
        res=max(res,ans);
        for(int i=0;i<nums.size()-1;i++){
            
            if(nums[i]+1==nums[i+1]){
                ans++;
            }
            else if(nums[i]==nums[i+1]) continue;
            else{
                ans=1;
            }
            res=max(res,ans);
        }
        return res;
    }
};