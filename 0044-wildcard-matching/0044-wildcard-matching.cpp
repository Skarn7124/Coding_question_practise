class Solution {
public:
    bool isMatch(string s, string p) {
        string wild = p;
        string pattern = s;
        string temp = "";
        int n = wild.size();
        for(int i = 0;i<n;i++){
            if(i!=0 && wild[i-1] == wild[i] && wild[i] == '*')
                continue;
            temp += wild[i];
        }
        wild = temp;
        if(wild == "*")
            return true;
        int m = pattern.size();
        n = wild.size();
        if(wild == pattern)
            return 1;
        if(m == 0)
            return 0;
        if(n == 0)
            return 0;
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        if(wild[n-1] == '*')
            dp[n-1][m] = 1;
        dp[n][m] = 1;
        for(int i = n-1;i>=0;i--){
            for(int j = m-1;j>=0;j--){
                if(pattern[j] == wild[i]){
                    dp[i][j] = dp[i+1][j+1];
                }
                else if(wild[i] == '?'){
                    dp[i][j] = dp[i+1][j+1];
                }
                else if(wild[i] == '*'){
                    dp[i][j] = dp[i+1][j] | dp[i][j+1] | dp[i+1][j+1];
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        // for(int i = 0;i<=n;i++){
        //     for(int j = 0;j<=m;j++)
        //         cout<<dp[i][j]<<" ";
        //     cout<<'\n';
        // }
        return dp[0][0];
    }
};