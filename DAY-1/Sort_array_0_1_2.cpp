#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        // TC--> O(N)*4
        // SC-->O(N)
        
        vector<int>v;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) v.push_back(nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1) v.push_back(nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==2) v.push_back(nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            nums[i]=v[i];
        }
        
        
        
        // TC--> O(NlogN)
        // SC-->O(1)
        
        
        sort(nums.begin(),nums.end());
        
        
        // TC--> O(N)*2
        // SC-->O(1)
        
        int r=0,g=0,b=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) r++;
            else if(nums[i]==1) g++;
            else b++;
        }
        for(int i=0;i<r;i++) nums[i]=0;
        for(int i=r;i<r+g;i++) nums[i]=1;
        for(int i=r+g;i<r+g+b;i++) nums[i]=2;
        
        
        // TC--> O(N)
        // SC-->O(1)
        
        int l=0;
        int mid = 0;
        int h = nums.size()-1;
        while(mid<=h){
            switch(nums[mid]){
                case 0:
                    swap(nums[l++],nums[mid++]);
                    break;
                case 1:
                    mid++;
                    break;
                case 2:
                    swap(nums[mid],nums[h--]);
                    break;
            }
        }
        
    }
};