class Solution {
public:
    int x,y;
    int numDecoding(string& s,int i,vector<int> &dp){
        if(dp[i] != -1)
            return dp[i];
        int n = s.size();
        if(n == 0)
            return 0;
        if(s[0] == '0')
            return 0;
        if(n == 1){
            return 1;
        }
        x = s[0]-'0',y = s[1]-'0';
        if(n == 2){
            if(10*x+y<=26 && y!=0)
                return 2;
            else if(10*x+y<=26 && y==0)
                return 1;
            else if(10*x+y>26 && y==0)
                return 0;
            else
                return 1;
        }
        string t1 = s.substr(1),t2 = s.substr(2);
        int ans = 0;
        if(10*x+y<=26)
            ans = numDecoding(t1,i+1,dp)+numDecoding(t2,i+2,dp);
        else
            ans = numDecoding(t1,i+1,dp);
        dp[i] = ans;
        return ans;
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1,-1);
        int ans = numDecoding(s,0,dp);
        return ans;
    }
};