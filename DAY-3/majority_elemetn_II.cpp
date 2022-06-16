// majority element greater than n/3

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1=-1;
        int num2=-1;
        int c1=0;
        int c2=0;
        for(auto i:nums){
            if(i==num1){
                c1++;
            }
            else if(i==num2) c2++;
            else if(c1==0){
                num1=i;
                c1=1;
            }
            else if(c2==0){
                num2=i;
                c2=1;
            }
            else{
                c1--;
                c2--;
            }
        }
        
        c1=0,c2=0;
        for(auto i:nums){
            if(i==num1) c1++;
            if(i==num2) c2++;
        }
        if(c1>nums.size()/3 && c2>nums.size()/3 && num1!=num2) return {num1,num2};
        else if(c1>nums.size()/3) return {num1};
        else if(c2>nums.size()/3)return {num2};
        return {};
        
        
    }
};