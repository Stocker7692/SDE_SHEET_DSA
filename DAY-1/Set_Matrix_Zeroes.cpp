#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE

class Solution
{
public:
    void setZeroes(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        map<pair<int, int>, int> m1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 0)
                {
                    m1[{i, j}]++;
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (m1[{i, j}] > 0)
                {
                    for (int k = 0; k < m; k++)
                    {
                        if (k != i && m1[{k, j}] == 0)
                        {
                            mat[k][j] = 0;
                        }
                        else if (k == i)
                            mat[k][j] = 0;
                    }

                    for (int k = 0; k < n; k++)
                    {
                        if (k != j && m1[{i, k}] == 0)
                        {
                            mat[i][k] = 0;
                        }
                        else if (k == j)
                            mat[i][k] = 0;
                    }
                }
            }
        }
    }
};

// OPTIMAL

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int col0 = 1, rows = matrix.size(), cols = matrix[0].size();

        for (int i = 0; i < rows; i++)
        {
            if (matrix[i][0] == 0)
                col0 = 0;
            for (int j = 1; j < cols; j++)
                if (matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;
        }

        for (int i = rows - 1; i >= 0; i--)
        {
            for (int j = cols - 1; j >= 1; j--)
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            if (col0 == 0)
                matrix[i][0] = 0;
        }
    }
};