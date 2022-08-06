#include<bits/stdc++.h>
using namespace std;

    bool isValid(int page,int A[],int N,int M){
        int student=1;
        int temp=0;
        for(int i=0;i<N;i++){
            
            if(A[i]>page) return 0;
            
            if(temp+A[i]>page){
                student++;
                temp=A[i];
                if(student>M) return 0;
            }
            else{
                temp+=A[i];
            }
        }
        
        return 1;
    }
    int findPages(int A[], int N, int M) 
    {
        //code here
        int l=0;
        int h=0;
        int res=0;
        for(int i=0;i<N;i++) h+=A[i];
        while(l<=h){
            int mid = (l+h)/2;
            if(isValid(mid,A,N,M)){
                res=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return res;
    }