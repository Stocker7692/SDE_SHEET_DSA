#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>&arr,int s,int e){
    int mid = (s+e)/2;
    
    int len1 = mid-s+1;
    int len2 = e-mid;
    
    int *first = new int [len1];
    int *second = new int [len2];
    
//     copy values
    int mainArrayIndex=s;
    
    for(int i=0;i<len1;i++){
        first[i]=arr[mainArrayIndex++];
    }
    
    for(int i=0;i<len2;i++){
        second[i]=arr[mainArrayIndex++];
    }
    
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex=s;
    
    while(index1<len1 && index2<len2){
        if(first[index1]<second[index2]){
            arr[mainArrayIndex++]=first[index1++];
        }
        else{
            arr[mainArrayIndex++]=second[index2++];
        }
    }
    
    while(index1<len1){
        arr[mainArrayIndex++]=first[index1++];
    }
    
    while(index2<len2){
        arr[mainArrayIndex++]=second[index2++];
    }
    
    delete []first;
    delete []second;
    
    
    
}
void solve(vector<int>&arr,int s,int e){
//     base case
    if(s>=e) return;
    
    int mid = (s+e)/2;
    
//     left part sort
    solve(arr,s,mid);
    
//     right part sort
    solve(arr,mid+1,e);
    
//     merge
    merge(arr,s,e);
    
    
}
void mergeSort(vector < int > & arr, int n) {
    // Write your code here.
    solve(arr,0,n-1);
}


int main() {

    
    int n = 15;
    vector<int>arr(n);
    for(int i=0;i<n;i++) arr[i]=100-i;

    mergeSort(arr, n);

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    } cout << endl;

    return 0;
}