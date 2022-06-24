#include<bits/stdc++.h>
using namespace std;

// BRUTE FORCE

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        set<vector<int>>s;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i]+nums[j]+nums[k]==0){
                        s.insert({nums[i],nums[j],nums[k]});
                    }
                }
            }
        }
        for(auto i:s) ans.push_back(i);
        return ans;
        
    }
};
// BETTER

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        set<vector<int>>s;
        int n = nums.size();
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        for(int i=0;i<n;i++){
            m[nums[i]]--;
            for(int j=i+1;j<n;j++){
                m[nums[j]]--;
                if(m[-(nums[i]+nums[j])]){
                    vector<int>temp={nums[i],nums[j],-(nums[i]+nums[j])};
                    sort(temp.begin(),temp.end());
                    s.insert(temp);
                }
                m[nums[j]]++;
                
            }
            m[nums[i]]++;
        }
        for(auto i:s) ans.push_back(i);
        return ans;
        
    }
};
// OPTIMAL

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        set<vector<int>>s;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=0;i<n;i++){
            int tgt = -nums[i];
            int l=i+1;
            int h=n-1;
            while(l<h){
                if(nums[l]+nums[h]==tgt){
                    s.insert({nums[i],nums[l],nums[h]});
                    l++;
                    h--;
                }
                else if(nums[l]+nums[h]<tgt) l++;
                else h--;
            }
        }
        for(auto i:s) ans.push_back(i);
        return ans;
        
    }
};