class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int mod = 1e9+7;
        vector<int> v(n,-1),dp(n,0),dp2(n,0);
        stack<int> s;
        for(int i = 0;i<n;i++){
            if(s.empty()){
                s.push(i);
            }
            else{
                while(!s.empty() && arr[s.top()]>arr[i]){
                    v[s.top()] = i;
                    s.pop();
                }
                s.push(i);
            }
        }
        long long int x = 0,j,ans = 0;
        for(int i = 0;i<n;i++){
            dp[i] += 1;
            if(v[i] != -1){
                dp[v[i]]+=dp[i];
            }
        }
        for(int i = 0;i<n;i++){
            if(v[i] != -1){
                dp2[i] = v[i]-i;
            }
            else{
                dp2[i] = n-i;
            }
        }
        for(int i = 0;i<n;i++){
            dp[i] = (dp[i]*dp2[i])%mod;
            cout<<dp[i]<<" ";
            dp[i]%=mod;
            arr[i]%=mod;
            x = ((long long int)dp[i]*arr[i])%mod;
            ans = (ans+x)%mod;
        }
        return ans;
    }
};