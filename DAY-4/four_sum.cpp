#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        set<vector<int>>s;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                for(int k=j+1;k<nums.size();k++){
                    int tgt = target-(nums[i]+nums[j]+nums[k]);
                    int l=k+1;
                    int h=nums.size()-1;
                    while(l<=h){
                        int mid = (l+h)/2;
                        if(nums[mid]==tgt){
                            s.insert({nums[i],nums[j],nums[k],nums[mid]});
                            break;
                            
                        }
                        else if(nums[mid]>tgt){
                            h--;
                        }
                        else l++;
                    }
                    
                }
            }
        }
        for(auto i:s) res.push_back(i);
        return res;
        
    }
};