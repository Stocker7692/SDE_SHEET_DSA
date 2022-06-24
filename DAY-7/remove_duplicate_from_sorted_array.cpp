#include<bits/stdc++.h>
using namespace std;


// TC: O(NlogN) SC:O(1)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        while(i<nums.size()-1){
            int j=i+1;
            while(j<nums.size() && nums[i]==nums[j]){
                nums[j]=INT_MAX;
                j++;
            }
            i=j;
        }  
        sort(nums.begin(),nums.end());
        for(i=0;i<nums.size();i++){
            if(nums[i]==INT_MAX) break;
        }
        return i;
    }
};
// TC: O(N) SC:O(N)

class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
       set < int > set;
       for (int i = 0; i < arr.size(); i++) {
           set.insert(arr[i]);
      }
      int k = set.size();
      int j = 0;
      for (int x: set) {
          arr[j++] = x;
      }
     return k;
    }
};
// TC: O(N) SC: O(1)

class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int i = 0;
        for (int j = 1; j < arr.size(); j++) {
            if (arr[i] != arr[j]) {
            i++;
            arr[i] = arr[j];
       }
      }
      return i + 1;
    }
};