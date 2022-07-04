/*
Date: 4/6/22

Problem: https://leetcode.com/problems/set-matrix-zeroes/
*/

// Solution 1: Time: O(mn) space: O(m+n)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vector<int> row(m,-1),col(n,-1);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    row[i]=0;
                    col[j]=0;
                }
            }
        }
        int i=0;
        while(i<m || i<n){
            if(i<m && row[i]==0){
                for(int j=0;j<n;j++){
                    matrix[i][j]=0;
                }
            }
            if(i<n && col[i]==0){
                for(int j=0;j<m;j++){
                    matrix[j][i]=0;
                }
            }
            i++;
        }
    }
};

// Solution 2: Time: O(mn), Space: O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool firstRow = false, firstCol = false;
        for(int i = 0; i<m;i++) {
            for(int j=0;j<n;j++) {
                if(matrix[i][j] == 0) {
                    if(i==0) firstRow = true;
                    if(j==0) firstCol = true;
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
       for(int i=1;i<m;i++) 
            if(matrix[i][0]==0) 
                for(int j=0;j<n;j++) 
                    matrix[i][j] = 0;
        for(int i=1;i<n;i++){
            if(matrix[0][i]==0) 
                for(int j=0;j<m;j++)
                    matrix[j][i] = 0;
        }
        if(firstRow)
           for(int i=0;i<n;i++)
              matrix[0][i] = 0;
        if(firstCol)
            for(int i=0;i<m;i++)
                matrix[i][0] = 0;
    }
};
