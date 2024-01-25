class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(),m = text2.size();
        vector<vector<int>> v(n+1,vector<int>(m+1));
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                if(text1[i-1] == text2[j-1]){
                    v[i][j] = 1+v[i-1][j-1];
                }
                else{
                    v[i][j] = max(v[i-1][j],v[i][j-1]);
                }
            }
        }
        return v[n][m];
    }
};