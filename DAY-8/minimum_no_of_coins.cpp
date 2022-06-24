#include<bits/stdc++.h>
using namespace std;

int findMinimumCoins(int V) 
{
    // Write your code here
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int M=9;
    int ans=0;
        sort(coins,coins+M);
        for(int i=M-1;i>=0;i--){
            while(V>=coins[i]){
                V-=coins[i];
                ans++;
            }
        }
        return ans;
}