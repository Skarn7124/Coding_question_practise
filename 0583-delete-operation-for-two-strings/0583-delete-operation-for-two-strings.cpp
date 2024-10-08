class Solution {
public:
    int gen(int i,int j,int n,int m,vector<vector<int>>&dp,string word1, string word2){
        if(i == n || j == m){
            return abs(n-i)+abs(m-j);
        }
        if(dp[i][j] != -1)  
            return dp[i][j];
        int ans = INT_MAX;
        if(word1[i] == word2[j]){
            ans = gen(i+1,j+1,n,m,dp,word1,word2);
        }
        else{
            ans = 1+gen(i+1,j,n,m,dp,word1,word2);
            ans = min(ans,1+gen(i,j+1,n,m,dp,word1,word2));
        }
        dp[i][j] = ans;
        return ans;
    }
    int minDistance(string word1, string word2) {
        int n = word1.size(),m = word2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int ans = gen(0,0,n,m,dp,word1,word2);
        return ans;
    }
};