class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans(2);
        map<int,int> m;
        int n = matches.size();
        for(int i = 0;i<n;i++){
            m[matches[i][1]]++;
            m[matches[i][0]]+=0;
        }
        for(auto it : m){
            if(it.second == 1){
                ans[1].push_back(it.first);
            }
            else if(it.second == 0){
                ans[0].push_back(it.first);
            }
        }
        return ans;
    }
};