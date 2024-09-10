class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& time) {
        sort(time.begin(),time.end());
        vector<vector<int>> ans;
        int a = time[0][0], b = time[0][1];
        int n = time.size();
        for(int i = 1;i<n;i++){
            if(b<time[i][0]){
                ans.push_back({a,b});
                a = time[i][0];
                b = time[i][1];
            }
            else{
                b = max(b,time[i][1]);
            }
        }
        ans.push_back({a,b});
        return ans;
    }
};