#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        // TC--> O(N2)
        // SC-->O(N2)

        int n = matrix.size();
        vector<vector<int>> mat(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mat[i][j]=matrix[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mat[i][j]=matrix[j][i];
            }
        }
        
        for(int i=0;i<n;i++){
            int j=0,k=n-1;
            while(j<=k){
                swap(mat[i][j++],mat[i][k--]);
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                matrix[i][j]=mat[i][j];
            }
        }


        // TC--> O(N2)
        // SC-->O(1)


        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
        
    }
};