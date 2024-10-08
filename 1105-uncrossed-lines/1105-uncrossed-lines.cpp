class Solution {
public:
    int gen(int i,int j,int n,int m,vector<int>& nums1, vector<int>& nums2,unordered_map<int,vector<int>>&a,unordered_map<int,vector<int>>&b,vector<vector<int>>&dp){
        if(i == n || j == m)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int ans = 0;
        if(nums1[i] == nums2[j]){
            ans = 1+gen(i+1,j+1,n,m,nums1,nums2,a,b,dp);
        }
        else{
            auto it = upper_bound(b[nums1[i]].begin(),b[nums1[i]].end(),j);
            auto itr = upper_bound(a[nums2[j]].begin(),a[nums2[j]].end(),i);
            if(it != b[nums1[i]].end()){
                ans = max(ans,1+gen(i+1,*it+1,n,m,nums1,nums2,a,b,dp));
            }
            ans = max(ans,gen(i+1,j,n,m,nums1,nums2,a,b,dp));
            ans = max(ans,gen(i,j+1,n,m,nums1,nums2,a,b,dp));
            if(itr != a[nums2[j]].end()){
                ans = max(ans,1+gen(*itr+1,j+1,n,m,nums1,nums2,a,b,dp));
            }
        }
        dp[i][j] = ans;
        return ans;
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,vector<int>> a,b;
        int n = nums1.size(),m = nums2.size();
        for(int i = 0;i<n;i++){
            a[nums1[i]].push_back(i);
        }
        for(int i = 0;i<m;i++){
            b[nums2[i]].push_back(i);
        }
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int ans = gen(0,0,n,m,nums1,nums2,a,b,dp);
        return ans;
    }
};