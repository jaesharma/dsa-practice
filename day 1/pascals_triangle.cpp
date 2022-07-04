/*
Date: 4/6/22

Problem: https://leetcode.com/problems/pascals-triangle/
*/

// Solution 1: 
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal;
        vector<int> temp;
        for(int i=0;i<numRows;i++){
            temp.clear();
            temp.push_back(1);
            for(int j=1;j<i;j++) {
                temp.push_back(pascal[i-1][j]+pascal[i-1][j-1]);
            }
            if(i!=0) temp.push_back(1);
            pascal.push_back(temp);
        }
        return pascal;
    }
};
