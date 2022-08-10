#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>nge;
        stack<int>st;
        int n = nums2.size();
        for(int i=n-1;i>=0;i--){
            
            if(st.size()==0) nge.push_back(-1);
            else if(st.size()>0 && st.top()>nums2[i]){
                nge.push_back(st.top());
            }
            else if(st.size()>0 && st.top()<=nums2[i]){
                while(st.size()>0 && st.top()<=nums2[i]) st.pop();
                if(st.size()==0) nge.push_back(-1);
                else nge.push_back(st.top());
            }
            st.push(nums2[i]);
            
        }
        
        reverse(nge.begin(),nge.end());
        
        
        return nge;
        
    }
};