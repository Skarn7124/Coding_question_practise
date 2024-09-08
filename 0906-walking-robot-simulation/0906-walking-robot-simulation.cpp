class Solution {
public:
    int robotSim(vector<int>& c, vector<vector<int>>& o) {
        set<vector<int>> s;
        for(auto it : o){
            s.insert(it);
        }
        int x = 0,y = 0,d = 0,ans = 0;
        vector<vector<int>> dis = {{0,1},{-1,0},{0,-1},{1,0}};
        for(auto it : c){
            if(it == -2){
                d = (d+5)%4;
            }
            else if(it == -1){
                d = (d+3)%4;
            }
            else{
                while(it--){
                    auto it = s.find({x+dis[d][0],y+dis[d][1]});
                    if(it == s.end()){
                        x += dis[d][0];
                        y += dis[d][1];
                        ans = max(x*x+y*y,ans);
                    }
                    else{
                        break;
                    }
                }
            }
        }
        return ans;
    }
};