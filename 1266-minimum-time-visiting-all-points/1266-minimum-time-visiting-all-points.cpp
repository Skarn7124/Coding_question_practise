class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        int x = -100000,y =-100000;
        for(auto it : points){
            if(x == -100000){
                x = it[0];
                y = it[1];
                continue;
            }
            ans += max(abs(it[0]-x),abs(it[1]-y));
            x = it[0];
            y = it[1];
        }
        return ans;
    }
};