// majority element greater than n/2

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt =0;
        int el;
        for(int i=0;i<nums.size();i++){
            if(cnt==0){
                el=nums[i];
            }
            if(el==nums[i]){
                cnt=cnt+1;
            }
            else{
                cnt=cnt-1;
            }
        }
        return el;
        
    }
};