#include<bits/stdc++.h>
using namespace std;

int findMedianSortedArrays(int nums1[], int nums2[],int n,int m,int k) {
        if(m<n) return findMedianSortedArrays(nums2,nums1,m,n,k);
        int n1 = n;
        int n2 = m;
        int l=max(0,k-m),h=min(k,n);
        while(l<=h){
            int cut1 = (l+h)>>1;
            int cut2 = k - cut1;
            
            int left1 = cut1==0?INT_MIN:nums1[cut1-1];
            int left2 = cut2==0?INT_MIN:nums2[cut2-1];
            int right1 = cut1==n1?INT_MAX:nums1[cut1];
            int right2 = cut2==n2?INT_MAX:nums2[cut2];
            
            if(left1<=right2 &&left2<=right1){
                return max(left1,left2);
            }
            else if(left1>right2) h=cut1-1;
            else l=cut1+1;
            
        }
        return 1;
    }