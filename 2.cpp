/*
  You are given an integer array nums sorted in non-decreasing order.

Build and return an integer array result with the same length as nums such that result[i] is equal to the summation of absolute differences between nums[i] and all the other elements in the array.

In other words, result[i] is equal to sum(|nums[i]-nums[j]|) where 0 <= j < nums.length and j != i (0-indexed).
*/
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n,0),suf(n,0);
        pre[0] = nums[0];
        suf[n-1] = nums[n-1];
        for(int i = 1;i<n;i++){
            pre[i] = pre[i-1]+nums[i];
            suf[n-i-1] = suf[n-i]+nums[n-i-1];
        }
        vector<int> ans(n,0);
        for(int i = 0;i<n;i++){
            ans[i] = -((pre[i]-nums[i]*i)+(nums[i]*(n-i-1)-suf[i]));
        }
        return ans;
    }
};
