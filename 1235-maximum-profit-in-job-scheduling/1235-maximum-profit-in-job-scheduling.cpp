class Solution {
public:
    int gen(int i,int n,vector<vector<int>>&v,vector<int>&dp,vector<int>&temp){
        if(i == n)
            return 0;
        if(dp[i] != -1)
            return dp[i];
        int ans = 0;
        auto it = lower_bound(temp.begin(),temp.end(),v[i][1]);
        int j = it-temp.begin();
        ans = v[i][2]+gen(j,n,v,dp,temp);
        ans = max(ans,gen(i+1,n,v,dp,temp));
        dp[i] = ans;
        return ans;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> v(n,vector<int>(3,0));
        vector<int> temp(n);
        for(int i = 0;i<n;i++){
            v[i][0] = startTime[i];
            v[i][1] = endTime[i];
            v[i][2] = profit[i];
        }
        sort(v.begin(),v.end());
        for(int i = 0;i<n;i++){
            temp[i] = v[i][0];
        }
        vector<int> dp(n+1,-1);
        int ans = gen(0,n,v,dp,temp);
        return ans;
    }
};