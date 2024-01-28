class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,vector<int>>m;
        unordered_map<int,int> vis;
        int n = adjacentPairs.size();
        vector<int> ans(n+1);
        int start = -1;
        for(int i = 0;i<n;i++){
            m[adjacentPairs[i][0]].push_back(adjacentPairs[i][1]);
            m[adjacentPairs[i][1]].push_back(adjacentPairs[i][0]);
        }
        for(int i = 0;i<n;i++){
            if(m[adjacentPairs[i][1]].size() == 1){
                start = adjacentPairs[i][1];
            }
            else if(m[adjacentPairs[i][0]].size() == 1){
                start = adjacentPairs[i][0];
            }
        }
        for(int i = 0;i<=n;i++){
            ans[i] = start;
            vis[ans[i]] = 1;
            start = m[start][0];
            if(vis[start] == 1 && m[ans[i]].size()>1){
                start = m[ans[i]][1];
            }
        }
        return ans;
    }
};