/*
Date: 4/6/22

Problem: https://leetcode.com/problems/maximum-subarray/
*/

// Solution 1: Kadane's algorithm
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, ans = INT_MIN;
        for(auto i:nums) {
            sum += i;
            ans = max(ans, sum);
            sum = max(sum, 0);
        }
        return ans;
    }
};

// Solution 2: Divide & conquer
