class Solution {
public:
    int gen(int i,int j,int n,int m,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(i == n-1 && j == m-1)
            return grid[i][j];
        if(dp[i][j] != -1)
            return dp[i][j];
        int ans = INT_MAX;
        if(i+1 < n)
            ans = grid[i][j] + gen(i+1,j,n,m,grid,dp);
        if(j+1 < m)
            ans = min(ans,grid[i][j] + gen(i,j+1,n,m,grid,dp));
        dp[i][j] = ans;
        return ans;
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int ans = gen(0,0,n,m,grid,dp);
        return ans;
    }
};