#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[1001];
    int solve(int i,string s,set<string>&st){
        if(i==s.size()) return 1;
        if(dp[i]!=-1) return dp[i];
        string temp="";
        for(int j=i;j<s.size();j++){
            temp+=s[j];
            if(st.find(temp)!=st.end()){
                if(solve(j+1,s,st)) return dp[i]=1;;
            }
        }
        return dp[i]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp,-1,sizeof(dp));
        set<string>st;
        for(auto i:wordDict) st.insert(i);
        return solve(0,s,st);
        
    }
};