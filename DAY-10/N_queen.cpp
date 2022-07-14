#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSafe(int row,int col,vector<string>&board,int n){
        int duprow = row;
        int dupcol = col;
        
        while(row>=0 && col>=0){
            if(board[row][col]=='Q'){
                return 0;
            }
            row--;
            col--;
        }
        
        row = duprow;
        col = dupcol;
        
        while(col>=0){
            if(board[row][col]=='Q'){
                return 0;
            }
            col--;
        }
        
        row = duprow;
        col = dupcol;
       
        while(row<n && col>=0){
            if(board[row][col]=='Q'){
                return 0;
            }
            row++;
            col--;
        }
        
        return 1;
    }
    void solve(int col,vector<string>&board,vector<vector<string>>&ans,int n){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col]='Q';
                solve(col+1,board,ans,n);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        solve(0,board,ans,n);
        return ans;
        
        
    }
};
// OPTIMIZED

class Solution {
public:
    void solve(int col,vector<string>&path,vector<vector<string>>&res,vector<int>&lowerDiagonal,vector<int>&leftSide,vector<int>&upperDiagonal,int n){
        if(col==n){
            res.push_back(path);
            return;
        }
        for(int row=0;row<n;row++){
            if(lowerDiagonal[row+col]==0 && leftSide[row]==0 && upperDiagonal[n-1+col-row]==0){
                path[row][col]='Q';
                lowerDiagonal[row+col]=1;
                leftSide[row]=1;
                upperDiagonal[n-1+col-row]=1;
                solve(col+1,path,res,lowerDiagonal,leftSide,upperDiagonal,n);
                lowerDiagonal[row+col]=0;
                leftSide[row]=0;
                upperDiagonal[n-1+col-row]=0;
                path[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>res;
        vector<string>path(n);
        string s(n,'.');
        for(int i=0;i<n;i++) path[i]=s;
        
        vector<int>lowerDiagonal(2*n-1,0);
        vector<int>leftSide(n,0);
        vector<int>upperDiagonal(2*n-1,0);
        solve(0,path,res,lowerDiagonal,leftSide,upperDiagonal,n);
        return res;
        
    }
};