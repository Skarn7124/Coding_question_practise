class Solution {
public:
    int gen(int i,int j,int n,int m,string w1,string w2,vector<vector<int>>&dp){
        if(i == n && j == m){
            return 0;
        }
        else if(i == n){
            return abs(j-m);
        }
        if(i>=n || j>=m){
            return abs(m-j)+abs(i-n);
        }
        if(dp[i][j] != -1)
            return dp[i][j];
        int ans1 = INT_MAX;
        if(w1[i] == w2[j]){
            ans1 = gen(i+1,j+1,n,m,w1,w2,dp);
        }
        else{
            
            ans1 = 1+gen(i,j+1,n,m,w1,w2,dp);
            ans1 = min(ans1,1+gen(i+1,j,n,m,w1,w2,dp));
            ans1 = min(ans1,1+gen(i+1,j+1,n,m,w1,w2,dp));
        }
        dp[i][j] = ans1;
        return ans1;

    }
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        if(n>m){
            swap(n,m);
            swap(word1,word2);
        }
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int x = abs(n-m);
        int ans = gen(0,0,n,m,word1,word2,dp);
        return ans;
    }
};