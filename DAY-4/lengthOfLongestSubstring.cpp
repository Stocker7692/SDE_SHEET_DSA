#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<int,int>m;
        int res=0;
        int curr=0;
        for(int i=0;i<s.size();i++){
            res = max(res,i-curr);
            if(m.find(s[i])!=m.end() && m[s[i]]>=curr){
                curr = m[s[i]]+1;
            }
            m[s[i]]=i;
        }
        if(res<s.size()-curr) return s.size()-curr;
        return res;
        
    }
};