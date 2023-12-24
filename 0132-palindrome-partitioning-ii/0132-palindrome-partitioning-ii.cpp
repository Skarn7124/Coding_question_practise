class Solution {
public:
    int minCut(string s) {
        
         // code here
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i = 0;i<n;i++){
            dp[i][i] = 1;
        }
        int maxl = 0,maxr = 0;
        int j,k;
        for(int i = 0;i<n;i++){
            j = i+1;
            k = i;
            while(j<n && k>=0){
                if(s[j] != s[k]){
                    break;
                }
                dp[k][j] = 1;
                if(s[j] == s[k]){
                    if(j+1<n)
                        j++;
                    else
                        break;
                    if(k-1>=0)
                        k--;
                    else
                        break;
                }
            }
            j = i+1;
            k = i-1;
            while(j<n && k>=0){
                if(s[j] != s[k]){
                    break;
                }
                dp[k][j] = 1;
                if(j+1<n)
                    j++;
                else
                    break;
                if(k-1>=0)
                    k--;
                else
                    break;
            }
        }
        int ans = n-1,temp;
        vector<int> cans(n+1,0);
        for(int i = n-1;i>=0;i--){
            temp = INT_MAX;
            for(int j = i;j<n;j++){
                if(dp[i][j] == 1){
                    temp = min(temp,1+cans[j+1]);
                }
            }
            cans[i] = temp;
        }
        return cans[0]-1;
    }
};