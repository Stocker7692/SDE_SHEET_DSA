#include<bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++) m[nums[i]]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        
        for(auto it:m){
            q.push({it.second,it.first});
            if(q.size()>k) q.pop();
        }
        vector<int>v;
        while(!q.empty()){
            v.push_back(q.top().second);
            q.pop();
        }
        return v;
        
    }