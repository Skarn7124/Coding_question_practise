class Solution {
public:
    int kInversePairs(int n, int k) {
        long long int z = ((long long int)n*(n-1))/2;
        if(k>z)
            return 0;
        if((z-k)<k)
            k = z-k;
        int mod = 1e9+7;
        vector<vector<int>> dp(n+1,vector<int>(k+1,0));
        long long int val = 0;
        dp[0][0] = 1;
        for(int i = 1;i<=n;i++){
            val = 0;
            for(int j = 0;j<=k;j++){
                val += (dp[i-1][j])%mod;
                if(j>=i){
                    val -= dp[i-1][j-i];
                }
                if(val<0){
                    val += mod;
                }
                val %= mod;
                dp[i][j] = val;
            }
        }
        return dp[n][k];
    }
};