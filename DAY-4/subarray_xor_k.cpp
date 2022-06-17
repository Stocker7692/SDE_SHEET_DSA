#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, int B) {
    unordered_map<int,int>m;
    int xorr = 0;
    int cnt =0;
    for(auto it:A){
        xorr = xorr^it;
        if(xorr==B){
            cnt++;
        }
        if(m.find(xorr^B)!=m.end()){
            cnt+=m[xorr^B];
        }
        m[xorr]+=1;
    }
    return cnt;
}