#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intr) {
           
        sort(intr.begin(),intr.end());
        vector<vector<int>>ans;
        int a=intr[0][0];
        int b =intr[0][1];
        for(int i=1;i<intr.size();i++){
            if(b>=intr[i][0]){
                b=max(b,intr[i][1]);
                
            }
            else{
                ans.push_back({a,b});
                a=intr[i][0];
                b=intr[i][1];
            }
           
        }
        ans.push_back({a,b});
        return ans;
        
        
    }
};