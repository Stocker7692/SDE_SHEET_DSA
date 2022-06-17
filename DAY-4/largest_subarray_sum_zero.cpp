#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        unordered_map<int,int>m;
        m[0]=-1;
        int presum=0;
    
        int maxlen=0;
        for(int i=0;i<n;i++){
            presum+=A[i];
            if(m.find(presum) !=m.end()){
                int len = i-m[presum];
                if(len>maxlen) maxlen = len;
            }
            else{
                m[presum]=i;
            }
        }
        return maxlen;
    }
};