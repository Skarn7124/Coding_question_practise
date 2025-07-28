class Solution {
public:
    int gen(int i,int n,int cur,int max,vector<int>& nums,vector<vector<int>>&dp){
        if(i == n){
            if(cur == max)
                return 1;
            return 0;
        }
        if(dp[i][cur] != -1)
            return dp[i][cur];
        dp[i][cur] = gen(i+1,n,cur|nums[i],max,nums,dp)+gen(i+1,n,cur,max,nums,dp);
        return dp[i][cur];
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int max = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            max |= nums[i];
        }
        vector<vector<int>> dp(n,vector<int>(max+1,-1));
        int ans = gen(0,n,0,max,nums,dp);
        return ans;
    }
};