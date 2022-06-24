#include<bits/stdc++.h>
using namespace std;


// BRUTE FORCE

class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        int n = height.size();
        for(int i=0;i<n;i++){
            int j=i-1;
            int maxLeft=height[i];
            while(j>=0){
                maxLeft = max(maxLeft,height[j]);
                j--;
            }
            j=i+1;
            int maxRight=height[i];
            while(j<n){
                maxRight = max(maxRight,height[j]);
                j++;
            }
            ans+=min(maxLeft,maxRight)-height[i];
            
        }
        return ans;
        
    }
};
// BETTER

class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        int n = height.size();
        int left[n],right[n];
        left[0]=height[0];
        for(int i=1;i<n;i++){
            left[i]=max(left[i-1],height[i]);
        }
        right[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            right[i]=max(right[i+1],height[i]);
        }
        for(int i=0;i<n;i++){
            ans+=min(left[i],right[i])-height[i];
        }
        return ans;
        
    }
};
// OPTIMAL

class Solution {
public:
    int trap(vector<int>& height) {
        int left=0,right=height.size()-1;
        int maxLeft=0,maxRight=0;
        int ans=0;
        while(left<=right){
            if(height[left]<=height[right]){
                if(height[left]>maxLeft){
                    maxLeft=height[left];
                }
                else{
                    ans+=maxLeft-height[left];
                }
                left++;
            }
            else{
                if(height[right]>maxRight){
                    maxRight = height[right];
                }
                else{
                    ans+=maxRight-height[right];
                }
                right--;
            }
        }
        return ans;
        
    }
};