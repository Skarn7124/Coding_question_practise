class Solution {
public:
    int gen(int i,int n,int j,int m,vector<vector<int>>&dp,vector<vector<int>>&grid){
        if(i == n || j == m || i<0 || j<0)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int ans = 1;
        if(j+1<m && grid[i][j+1]>grid[i][j]){
            ans = 1+gen(i,n,j+1,m,dp,grid);
        }
        if(i>=1 && j+1<m && grid[i-1][j+1]>grid[i][j]){
            ans = max(ans,1+gen(i-1,n,j+1,m,dp,grid));
        }
        if(i+1<n && j+1<m && grid[i+1][j+1]>grid[i][j]){
            ans = max(ans,1+gen(i+1,n,j+1,m,dp,grid));
        }
        dp[i][j] = ans;
        return ans;
    }
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int ans = 0,cur;
        for(int i = 0;i<n;i++){
            cur = gen(i,n,0,m,dp,grid);
            ans = max(ans,cur);
        }
        return ans-1;
    }
};