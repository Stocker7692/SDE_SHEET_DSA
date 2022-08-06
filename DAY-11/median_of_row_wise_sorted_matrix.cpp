#include<bits/stdc++.h>
using namespace std;

int cntSmallerThanMid(vector<int>&row,int mid){
    int l=0,h=row.size()-1;
    while(l<=h){
        int md=(l+h)/2;
        if(row[md]<=mid) l=md+1;
        else h=md-1;
    }
    return l;
}

int findMedian(vector<vector<int> > &A) {
    int l=1;
    int h=1e9;
    int n = A.size();
    int m= A[0].size();
   
    while(l<=h){
        int mid = (l+h)/2;
         int cnt=0;
        for(int i=0;i<n;i++){
            cnt+=cntSmallerThanMid(A[i],mid);
        }
        if(cnt<=(n*m)/2) l=mid+1;
        else h=mid-1;
    }
    return l;
}