#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long nn = n;
        if(nn<0) nn=nn*-1;
        while(nn){
            if(nn%2==1){
                ans = ans*x;
                nn=nn-1;
            }
            else{
                x=x*x;
                nn=nn/2;
                
            }
        }
        if(n<0) ans = (double)(1.0)/(double)(ans);
        return ans;
        
        
    }
};

class Solution {
public:
    double myPow(double x, int n) {
        int ans;
        if(n==0){
            return 1;
        }
        if (n < 0) { 
            n = abs(n);
            x = 1/x;
        }
        if(n%2==0){
            return myPow(x*x,n/2);
        
        }else{
            return x*myPow(x*x,n/2);
        }
        
    }
};