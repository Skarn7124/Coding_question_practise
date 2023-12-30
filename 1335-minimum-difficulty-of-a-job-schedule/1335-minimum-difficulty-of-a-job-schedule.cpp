class Solution {
public:
    int gen(int i,int n,int prev,int d,vector<int>&jobDifficulty,vector<vector<int>>&dp){
        if(i == n)
            return 0;
        if(dp[prev+1][d]!=-1)
            return dp[prev+1][d];
        if(d == 0){
            int y = 0;
            for(int j = prev+1;j<n;j++){
                y = max(y,jobDifficulty[j]);
            }
            dp[prev+1][d] = y;
            return y;
        }
        if(n-i == d+1){
            int y = 0;
            for(int j = prev+1;j<=i;j++){
                y = max(y,jobDifficulty[j]);
            }
            for(int j = i+1;j<n;j++){
                y += jobDifficulty[j];
            }
            dp[prev+1][d] = y;
            return y;
        }
        int y = 0;
        for(int j = prev+1;j<=i;j++){
            y = max(y,jobDifficulty[j]);
        }
        int ans1 = INT_MAX;
        if(d>=1)
            ans1 = gen(i+1,n,i,d-1,jobDifficulty,dp);
        if(ans1 != INT_MAX)
            ans1 += y;
        int ans2 = INT_MAX;
        ans2 = gen(i+1,n,prev,d,jobDifficulty,dp);
        if(dp[prev+1][d] != -1)
            dp[prev+1][d] = min(min(ans1,ans2),dp[prev+1][d]);
        else
            dp[prev+1][d] = min(ans1,ans2);
        return dp[prev+1][d];
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(n<d)
            return -1;
        vector<vector<int>> dp(n+1,vector<int>(d+1,-1));
        int ans = 0;
        d--;
        ans = gen(0,n,-1,d,jobDifficulty,dp);
        return ans;
    }
};