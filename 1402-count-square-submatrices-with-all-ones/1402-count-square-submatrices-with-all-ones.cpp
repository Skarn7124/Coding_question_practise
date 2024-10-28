class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(i == 0 || j == 0){
                    dp[i][j] = matrix[i][j];
                }
                else if(matrix[i][j] == 1){
                    dp[i][j] = min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
                }
                // cout<<dp[i][j]<<" ";
                ans += dp[i][j];
            }
            // cout<<'\n';
        }
        return ans;
    }
};