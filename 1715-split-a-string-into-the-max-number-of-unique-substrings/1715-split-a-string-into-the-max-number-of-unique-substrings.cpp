class Solution {
public:
    int gen(string s,int i,int n,vector<int>&dp,unordered_map<string,int>&mp){
        if(i == n)
            return 0;
        // if(dp[i] != -1)
        //     return dp[i];
        string t = "";
        int ans = 0;
        for(int j = i;j<n;j++){
            t += s[j];
            if(mp[t] == 0){
                mp[t]++;
                ans = max(ans,1+gen(s,j+1,n,dp,mp));
                mp[t]--;
            }
        }
        // dp[i] = ans;
        return ans;
    }
    int maxUniqueSplit(string s) {
        int n = s.size();
        vector<int> dp(n+1,-1);
        unordered_map<string,int>mp;
        int ans = gen(s,0,n,dp,mp);
        return ans;
    }
};