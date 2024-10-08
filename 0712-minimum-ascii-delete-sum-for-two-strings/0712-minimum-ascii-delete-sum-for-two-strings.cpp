class Solution {
public:
    string word1;
    string word2;
    int gen(int i,int j,int n,int m,vector<vector<int>>&dp){
        if(i == n || j == m){
            int ans = 0;
            while(i<n){
                ans += word1[i];
                i++;
            }
            while(j<m){
                ans += word2[j];
                j++;
            }
            return ans;
        }
        if(dp[i][j] != -1)  
            return dp[i][j];
        int ans = INT_MAX;
        if(word1[i] == word2[j]){
            ans = gen(i+1,j+1,n,m,dp);
        }
        else{
            ans = (int)word1[i]+gen(i+1,j,n,m,dp);
            ans = min(ans,(int)word2[j]+gen(i,j+1,n,m,dp));
        }
        dp[i][j] = ans;
        return ans;
    }
    int minimumDeleteSum(string s1, string s2) {
        word1 = s1,word2 = s2;
        int n = s1.size(),m = s2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int ans = gen(0,0,n,m,dp);
        return ans;
    }
};